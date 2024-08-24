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


vector<vector<int>> chessboard(8, vector<int>(8, 0));
int sol = 0;

bool conflict(int row, int col) {

	for (int i = 1; i < 8; i++) {
		if (row - i < 0) break;

		if (chessboard[row - i][col] == 1)
			return true;

		if (col + i <= 7 && chessboard[row - i][col + i] == 1)
			return true;

		if (col - i >= 0 && chessboard[row - i][col - i] == 1)
			return true;
	}

	return false;
}

void place_queen(int row) {
	for (int col = 0; col < 8; col++) {
		if (chessboard[row][col] == -1) continue;
		chessboard[row][col] = 1;

		if (row == 0 || !conflict(row, col)) {
			if (row < 7)
				place_queen(row + 1);
			else
				sol++;
		}

		chessboard[row][col] = 0;
	}
}

void run_case() {
	string line;

	for (int i = 0; i < 8; i++) {
		cin >> line;

		for (int j = 0; j < 8; j++)
			if (line[j] == '*')
				chessboard[i][j] = -1;
	}

	place_queen(0);
	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}