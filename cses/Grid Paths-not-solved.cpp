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

template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename = enable_if_t<!is_same_v<string, T_container>, typename T_container::value_type>> ostream &operator<<(ostream &os, const T_container &arg) { for (const auto &x : arg) os << x << ' '; return os; } 

template <typename> struct is_tuple: std::false_type {};
template <typename ...T> struct is_tuple<std::tuple<T...>>: std::true_type {};
template<typename T> void tuple_out(T &&t) { apply([](auto &&...arg) { ((cout << arg << ' '), ...) << '\n'; }, t); }

template <typename T> void _deduce(T arg) { if constexpr (is_tuple<T>::value) { tuple_out(arg); } else { cerr << arg << ' '; } }
template<typename... Arg> void println(Arg&&... args) { (_deduce(args), ...); cerr << '\n'; }

vector<vector<bool>> vis(7, vector<bool>(7, false));
string A;

bool not_visited(int i, int j) {
	return i >= 0 && i < 7 && j >= 0 && j < 7 && !vis[i][j];
}

int sol = 0;

void dfs(int cur, int i, int j) {
	if (i == 6 && j == 6 && cur == 48) {
		sol++;
		return ;
	}

	vis[i][j] = true;

	if (A[cur] == '?' || A[cur] == 'L') {
		if (not_visited(i, j - 1)) {
			if (!(!not_visited(i, j - 2) && not_visited(i, )))
		}
	}
}

void run_case() {
	cin >> A;

	dfs(0, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}