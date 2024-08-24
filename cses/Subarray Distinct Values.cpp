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

#ifdef PO_DEBUG
#define dbug_out(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "): ", println(__VA_ARGS__)
#else
#define dbug_out(...)
#endif

/* [0]

	this is like a prefix sum, N = 5, K = 2
		ie: [1] 				-> comb: [1]
			[1, 2] 				-> comb: [1], 		[2]
										 [1, 2]
			[1, 2, 3]			-> comb: [1], 		[2]
										 [1, 2]		[2, 3]

			[1, 2, 1, 2, 3] 	-> comb: [1]			[2]			[1]			[2]			[3]
										 [1, 2]			[2, 1]		[1, 2]		[2, 3]
										 [1, 2, 1]		[2, 1, 2]	
										 [1, 2, 1, 2]	

			therefore, [0, 0] -> [1]										-> 0 - 0 + 1
					   [0, 1] -> [2], [1, 2]								-> 1 - 0 + 1
					   [0, 2] -> [1], [2, 1], [1, 2, 1]						-> 2 - 0 + 1
					   [0, 3] -> [2], [1, 2], [2, 1, 2], [1, 2, 1, 2]		-> 3 - 0 + 1
					   [3, 4] -> [3], [2, 3]								-> 4 - 3 + 1

			each time add a new element, is like adding several combination
*/

void run_case() {
	int64_t N, M;
	cin >> N >> M;
	vector<int64_t> A(N);
	for (auto &x : A)	
		cin >> x;

	int64_t distinct = 0, cnt = 0;

	unordered_map<int64_t, int64_t> m;
	for (int64_t end = 0, start = 0; end < N; end++) {

		if (!m[A[end]])
			distinct++;
		m[A[end]]++;

		while (distinct > M) {
			m[A[start]]--;

			if (!m[A[start++]])
				distinct--;
		}

		// count all the combination, see [0]
		cnt += end - start + 1;
		dbug_out(start, end);
	}

	cout << cnt << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	run_case();
    
	return 0;
}
