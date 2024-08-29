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

void run_case() {
	int N;
	cin >> N;

	vector<array<int, 3>> A(N);
	for (auto &[a, b, c] : A)	// end, start, val
		cin >> b >> a >> c;

	sort(A.begin(), A.end());	

	cout << "debug: ";
	for (auto &[a, b, c] : A)
		cout << '(' << a << ", " << b << ", " << c << ')' << ' ';
	cout << '\n';


	vector<int> dp(N + 1);

	for (int i = 1; i < N + 1; i++) {
		int start = A[i - 1][1];
		int val = A[i - 1][2];

		int previous = lower_bound(A.begin(), A.end(), array {start, 0, 0}) - A.begin();
		dbug_out(A[previous][0], start, dp[i - 1], val, dp[previous]);
		dp[i] = max(dp[i - 1], val + dp[previous]);
		dbug_out(dp);
	}

	dbug_out(dp);

	cout << dp.back() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}