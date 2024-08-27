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


const int64_t MOD = int64_t(1e9 + 7);

void run_case() {
	int64_t N, UP;
	cin >> N >> UP;

	vector<int64_t> A(N);
	for (auto &x : A)
		cin >> x;

	vector<vector<int64_t>> dp(N, vector<int64_t>(UP + 2, 0));

	for (int64_t i = 0; i < N; i++) {
		if (i == 0) {
			if (A[i] == 0) {
				for (int64_t j = 1; j <= UP; j++)
					dp[i][j] = 1;
			} else {
				dp[i][A[i]] = 1;
			}
		} else {
			if (A[i] == 0) {
				for (int64_t j = 1; j <= UP; j++) {
					dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
				}
			} else {
				int64_t &val = A[i];
				dp[i][val] = (dp[i - 1][val] + dp[i - 1][val - 1] + dp[i - 1][val + 1]) % MOD;
			}
		}
	}

	cout << accumulate(dp.back().begin(), dp.back().end(), 0LL) % MOD << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}