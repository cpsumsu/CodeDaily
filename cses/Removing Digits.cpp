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

template<typename T> T out(T &&t) { if constexpr (is_integral_v<T>) { if (t == INT_MAX || t == INT_MIN) return -1; } else return t; }

template <typename T> void _deduce(T arg) { if constexpr (is_tuple<T>::value) { tuple_out(arg); } else { cerr << out(arg) << ' '; } }
template<typename... Arg> void println(Arg&&... args) { (_deduce(args), ...); cerr << '\n'; }

#define dbug_out(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "): ", println(__VA_ARGS__)
#else
#define dbug_out(...)
#endif

// // Greedy, not work 
// void run_case() {
// 	int T;
// 	cin >> T;

// 	int cnt = 0;

// 	while (T / 10) {
// 		int last = T % 10;

// 		if (!last) {
// 			auto t = to_string(T);
// 			last = t[t.find_last_not_of('0')] - '0';
// 		}

// 		dbug_out(last, T);
// 		T -= last;
// 		cnt++;
// 	}

// 	cout << cnt + 1 << '\n';
// }

// https://hackmd.io/@RaisoLiu/S1XI2aXmi
void run_case() {
	int n;
	cin >> n;
	vector<int> dp(n + 1, INT_MAX);

	dp[0] = 0;
	for(int i = 1; i <= n; i++) {

		// loop every digits of i to find out the mini 
		for(int k = i; k > 0; k /= 10) if(k % 10 > 0) {
			dp[i] = min(dp[i], dp[i - k%10] + 1);
		}
	}

	cout << dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}