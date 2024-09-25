/*
ID: dc22762@um.edu.mo
TASK: wormhole
LANG: C++20
*/
#include <iostream>
#include <climits>
#include <utility>
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
    ifstream in("wormhole.in");
    ofstream out("wormhole.out");

    int N;
    in >> N;
    vector<pair<int, int>> A(N);
    for (auto &[a, b]: A)
        in >> a >> b;

    sort(A.begin(), A.end(), [](auto &a, auto &b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    unordered_map<int, int> move_down;
    for (int i = 0; i < N - 1; i++)
        if (A[i].second == A[i + 1].second)
            move_down[i] = i + 1;

    vector<int> match(N, -1);

    auto have_cycle = [&]() -> bool {
        for (int i = 0; i < N; i++) {
            vector<bool> vis(N);

            for (int x = i; move_down.contains(x); x = match[move_down[x]]) {
                if (vis[x])
                    return true;
                vis[x] = true;
            }
        }

        return false;
    };

    int sol = 0;
    auto dfs = make_y_combinator([&](auto &&dfs, int cur) -> void {
        if (cur == N) {
            sol += int(have_cycle());
            return ;
        }

        if (match[cur] != -1)
            dfs(cur + 1);
        else
            for (int i = cur + 1; i < N; i++) {
                if (match[i] == -1) {
                    match[cur] = i;
                    match[i] = cur;

                    dfs(cur + 1);

                    match[cur] = -1;
                    match[i] = -1;
                }
            }
    });

    dfs(0);
    out << sol << '\n';
}

int main() {
    fastio
    run_case();
}
