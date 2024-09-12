// https://codeforces.com/problemset/problem/2009/D
#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <stack>
#include <list>
#include <deque>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename = enable_if_t<!is_same_v<string, T_container>, typename T_container::value_type>> ostream &operator<<(ostream &os, const T_container &arg) { for (const auto &x : arg) os << x << ' '; return os; } 

#ifdef PO_DEBUG
template <typename> struct is_tuple: std::false_type {};
template <typename ...T> struct is_tuple<std::tuple<T...>>: std::true_type {};
template<typename T> void tuple_out(T &&t) { apply([](auto &&...arg) { ((cout << arg << ' '), ...) << '\n'; }, t); }

template <typename T> void _deduce(T arg) { if constexpr (is_tuple<T>::value) { tuple_out(arg); } else { cerr << arg << ' '; } }
template<typename... Arg> void println(Arg&&... args) { (_deduce(args), ...); cerr << '\n'; }

#define dbug_out(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "): ", println(__VA_ARGS__)
#else
#define dbug_out(...)
#endif

void run_case() {
    int64_t N;
    cin >> N;

    set<int64_t> zeros, ones;

    for (int64_t i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;

        if (!b) {
            zeros.insert(a);
        } else {
            ones.insert(a);
        }
    }    

    int64_t sol = 0;
    for (auto &x : zeros) {
        if (ones.contains(x))
            sol += ones.size() - 1;

        if (x - 1 >= 0 && x + 1 <= N && ones.contains(x - 1) && ones.contains(x + 1))
            sol++;
    }

    for (auto &x : ones) {
        if (zeros.contains(x))
            sol += zeros.size() - 1;

        if (x - 1 >= 0 && x + 1 <= N && zeros.contains(x - 1) && zeros.contains(x + 1))
            sol++;
    }

    cout << sol << '\n';
}

int main() {
    fastio

    int tests;
    cin >> tests;
    while (tests-- > 0)
        run_case();
    
    return 0;
}