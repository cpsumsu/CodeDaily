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
	int64_t N, M;
	cin >> N >> M;

	vector<int64_t> A(N);
	for (auto &x : A)	
		cin >> x;

	for (int64_t i = 0; i < N; i++)
		A.push_back(A[i]);

	vector<int64_t> prefix_sum(2 * N + 1, 0);
	partial_sum(A.begin(), A.end(), next(prefix_sum.begin()));

	auto query = [&](int64_t prefix) {
		int64_t start = prefix / N;
		int64_t ans = start * prefix_sum[N];
		int64_t remains = prefix_sum[start + prefix % N] - prefix_sum[start];

		return ans + remains;
	};

	for (int64_t i = 0; i < M; i++) {
		int64_t L, R;
		cin >> L >> R;
		L--;

		cout << query(R) - query(L) << '\n';
	}
}

int main() {
	fastio
    
    int tests;
    cin >> tests;
    while (tests-- > 0)
		run_case();
    
	return 0;
}