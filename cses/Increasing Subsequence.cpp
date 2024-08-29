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

#define all(x) (x).begin(), (x).end()


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

// // O(nlogn)
// void run_case() {
// 	int N;
// 	cin >> N;

// 	vector<int> A(N);
// 	for (auto &x : A )	
// 		cin >> x;

// 	vector<int> ret;

// 	for (auto &x : A) {
// 		auto it = lower_bound(ret.begin(), ret.end(), x);

// 		if (it != ret.end())
// 			*it = x;
// 		else
// 			ret.push_back(x);
// 	}

// 	cout << ret.size() << '\n';
// }


void run_case() {
	int N;
	cin >> N;

	vector<int> A(N);
	for (auto &x : A)
		cin >> x;

	vector<int> dp(N + 1, 1);
	int sol = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		sol = max(sol, dp[i]);
	}

	cout << sol << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}