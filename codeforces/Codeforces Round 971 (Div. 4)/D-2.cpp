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
	int N;
	cin >> N;

	vector<vector<bool>> grid(2, vector<bool>(N + 1, false));

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		grid[b][a] = true;
	}

	int64_t triangles = 0;

	for (int x = 1; x < N; x++)
		for (int y = 0; y < 2; y++)
			triangles += grid[y][x] && grid[!y][x - 1] && grid[!y][x + 1];

	for (int i = 0; i < N + 1; i++)
		if (grid[0][i] && grid[1][i])
			triangles += N - 2;

	cout << triangles << '\n';
}

int main() {
	fastio
    
    int tests;
    cin >> tests;
    while (tests-- > 0)
		run_case();
    
	return 0;
}