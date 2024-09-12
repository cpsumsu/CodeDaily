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

#include <cassert>

void run_case() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i < N; i++)
        A[i] += N - i;

    multiset<int> ms;
    // frequency len < 2 * N + 1, since A[i] += N - i, so max(A[i]) == 2 * N
    vector<int> frequency(2 * N + 1, 0), ans(N, -1);

    auto moving = [&](int x, int freq) {
        auto it = ms.find(frequency[x]);

        if (it != ms.end())
            ms.erase(it);

        frequency[x] += freq;
        ms.insert(frequency[x]);
    };

    for (int i = 0; i < N; i++) {
        moving(A[i], 1);

        if (i >= K - 1) {
            ans[i - (K - 1)] = K - *ms.rbegin();
            moving(A[i - (K - 1)], -1);
        }
    }

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;

        cout << ans[L] << '\n';
    }
}

int main() {
    fastio
    
    int tests;
    cin >> tests;
    while (tests-- > 0)
        run_case();
    
    return 0;
}