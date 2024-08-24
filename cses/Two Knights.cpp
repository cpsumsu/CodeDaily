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

// https://www.geeksforgeeks.org/cses-solutions-two-knights/

// to make it claer, k^2 * (k^2 - 1) / 2 => comb(k^2, 2), place two knights in k * k chessboard
// to remove attack position, find all the 3 * 2 and 2 * 3 block. ie: in 3 * 3 chessboard, 2 * 3 (from top to down) 2, then switch position.
// say the first two 2 * 3 block is [(0, 0), (1, 2)] and [(1, 0), (2, 2)] switch to [(1, 0), (0, 2)] and [(2, 0), (1, 2)]. 
// 2 * 3 and 3 * 2 => (k - 1) * (k - 2) if k * k >= 3. since 2 * 3 and 3 * 2 can switch for each situation, so 2 * 2 = 4
// formula -> (k - 1) * (k - 2) * 4
void run_case() {
	int64_t N;
	cin >> N;

	for (int64_t k = 1; k <= N; k++) {
		int64_t a = k * k, b = a * (a - 1) / 2;
		int64_t ans = b;

		if (k >= 3)
			ans -= 4 * (k - 1) * (k - 2);

		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}