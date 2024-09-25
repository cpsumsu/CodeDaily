/*
ID: dc22762@um.edu.mo
TASK: skidesign
LANG: C++20
*/
#include <iostream>
#include <climits>
#include <vector>
#include <array>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <cassert>
#include <cstdint>
#include <fstream>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

template <class F>
struct y_combinator {
    F f;
    template <class... Args>
    decltype(auto) operator()(Args&&... args) const { return f(*this, std::forward<Args>(args)...); }
};
template <class F> y_combinator<std::decay_t<F>> make_y_combinator(F&& f) { return {std::forward<F>(f)}; }

template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = enable_if_t<!is_same_v<T_container, string>, typename T_container::value_type>> ostream &operator<<(ostream &os, const T_container &arg) { os << '{'; string sep; for (const T &x : arg) os << sep << x, sep = ", "; return os << '}'; }

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
    ifstream in("skidesign.in");
    ofstream out("skidesign.out");

    int N;
    in >> N;

    vector<int> A(N);
    for (auto &x : A)
        in >> x;

    int sol = 1e9   ;
    for (int i = 0; i <= 100 - 17; i++) {
        int upper = i + 17;
        int total = 0;

        for (int x : A)
            if (x > upper) 
                total += (x - upper) * (x - upper);
            else if (x < i)
                total += (i - x) * (i - x);

        sol = min(sol, total);
    }

    out << sol << '\n';
}

int main() {
    run_case();
}
