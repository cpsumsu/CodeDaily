#include <iostream>
#include <climits>
#include <variant>
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

vector<vector<int64_t>> cached;
int64_t N, M;
const int64_t MOD = 1e9 + 7;

int64_t dfs(int64_t x, int64_t y) {
	dbug_out(x, y);
	if (x >= N || y >= N)
		return 0;

	if (cached[x][y] != -1)
		return cached[x][y];

	if (x == N - 1 && y == N - 1)
		return 1;

	return cached[x][y] = (dfs(x + 1, y) + dfs(x, y + 1)) % MOD;
}

void run_case() {
	cin >> N;
	vector<string> A(N);

	cached.assign(N, vector<int64_t>(N, -1));

	for (auto &x : A)
		cin >> x;

	for (int64_t i = 0; i < N; i++) {
		for (int64_t j = 0; j < N; j++)
			if (A[i][j] == '*')
				cached[i][j] = 0;
	}


	cout << dfs(0, 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

	run_case();
    
	return 0;
}