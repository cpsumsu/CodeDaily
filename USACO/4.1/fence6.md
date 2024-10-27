# Fence Loops

[question](https://usaco.training/usacoprob2?a=8cvqq0t1jHZ&S=fence6) or search it in [luogu](https://www.luogu.com.cn/problem/P2738)

A lot of weird, complicated solution posted on luogu, but I have found that they are overkilled (most of the solutions build a adjacency matrix and solve it with Floyd Warshall as to find shortest path start from each vertices. Instead, we can separate a segment into left node and right node, such that use simply dfs to solve it.

# example

suppose we have a snippet of graph (full graph in question example).

First, we start from left side of segment 1, then we aim to traverse its right side which is segment 10. For segment 10, segment 1 is its left side, so next step is to traverse right side of segment 10. Segment 10 is the right side of segment 9, then traverse the left side of segment 9......

Follow this logic, we can travese the graph using dfs. If we detect it forms a cycle, then update the smallest path

```
        1
------------------
                 |
                 |
                 |
                 |
             \   |   10
              \  |
               \ |
            9   \|
                 \
```

# solution

deal with input.

```cpp
int N;
cin >> N;

vector<int> fence_len(N);           // record length of fences
vector<vector<int>> left(N), right(N);      // record the left node and right node on each fence
vector<vector<char>> direction(N, vector<char>(N));        // to recognize whether whether the adjacent node is left or right during traversal

for (int i = 0; i < N; i++) {
    int a, b, c;
    cin >> a >> fence_len[a - 1] >> b >> c;
    a--;                                // personal habit, I perfer start with 0

    int x;
    for (int j = 0; j < b; j++) {
        cin >> x;
        x--;
        left[a].push_back(x);           // record the left node of a
        direction[a][x] = 'L';
    }

    for (int j = 0; j < c; j++) {
        cin >> x;
        x--;
        right[a].push_back(x);          // record the right node of a
        direction[a][x] = 'R';
    }
}
```

traverse the graph using simply dfs

```cpp
vector<bool> visited(N);
int smallest = 1e9;

void dfs(int u, char dir, int len) {
    if (visited[u]) {                       // if encounter a visited node, which means it has reached a cycle, so update the smallest paths
        smallest = min(smallest, len);
        return ;
    }

    visited[u] = true;

    if (dir == 'R') {                       // if it is started from right side, which means we aim to traverse its another side (left)
        for (auto v : left[u])
            self(v, direction[v][u], len + fence_len[u]);
    } else {
        for (auto v : right[u])
            self(v, direction[v][u], len + fence_len[u]);
    }

    visited[u] = false;
}

for (int i = 0; i < N; i++) {
    visited.resize(N, false);
    dfs(i, 'L', 0);                     // L means start from L side. Actually doesn't matter start from left or right
}
```

**NOTE**: direction is a bit hard to understand, but consider the example, we know that we don't know the relative direction of each segment. For example, in segment 10, we don't know the right side or left side of segment 9 attached to segment 10, so it is necessary to record it.

# complete code

```cpp
#include <cstdlib>
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
    int N;
    cin >> N;

    vector<int> fence_len(N);
    vector<vector<int>> left(N), right(N);
    vector<vector<char>> direction(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> fence_len[a - 1] >> b >> c;
        a--;

        int x;
        for (int j = 0; j < b; j++) {
            cin >> x;
            x--;
            left[a].push_back(x);
            direction[a][x] = 'L';
        }

        for (int j = 0; j < c; j++) {
            cin >> x;
            x--;
            right[a].push_back(x);
            direction[a][x] = 'R';
        }
    }

    vector<bool> visited(N);
    int smallest = 1e9;

    auto dfs = make_y_combinator([&](auto &&self, int u, char dir, int len) -> void {
        if (visited[u]) {
            smallest = min(smallest, len);
            return ;
        }

        visited[u] = true;

        if (dir == 'R') {
            for (auto v : left[u])
                self(v, direction[v][u], len + fence_len[u]);
        } else {
            for (auto v : right[u])
                self(v, direction[v][u], len + fence_len[u]);
        }

        visited[u] = false;
    });

    for (int i = 0; i < N; i++) {
        visited.resize(N, false);
        dfs(i, 'L', 0);
    }

    cout << smallest << '\n';
}

int main() {
    fastio
    run_case();
}
```
