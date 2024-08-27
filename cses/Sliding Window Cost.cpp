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

// similar to previous question (https://cses.fi/problemset/task/1076), the hard part is to quick calculate the sum of lower and upper part
void run_case() {
	int64_t N, K;
	cin >> N >> K;

	vector<int64_t> A(N);
	for (auto &x : A)
		cin >> x;

	multiset<int64_t> lower, upper;
	lower.insert(A.front());

	int64_t lower_sum = A.front(), upper_sum = 0;

	auto increment = [&](int64_t val) {
		auto last = *lower.rbegin();

		if (last < val) {
			upper.insert(val);
			upper_sum += val;

			if (int(upper.size()) > K / 2) {
				lower_sum += *upper.begin();
				upper_sum -= *upper.begin();

				lower.insert(*upper.begin());
				upper.erase(upper.begin());
			}
		} else {

			lower.insert(val);
			lower_sum += val;

			if (int(lower.size()) > K / 2 + 1) {
				lower_sum -= *lower.rbegin();
				upper_sum += *lower.rbegin();

				upper.insert(*lower.rbegin());
				lower.erase(lower.find(*lower.rbegin()));
			}
		}
	};

	auto remove = [&](int64_t val) {
		if (auto it = lower.find(val); it != lower.end()) {
			lower_sum -= val;
			lower.erase(it);
		} else {
			upper_sum -= val;
			upper.erase(upper.find(val));
		}

		if (lower.empty()) {
			lower_sum += *upper.begin();
			upper_sum -= *upper.begin();

			lower.insert(*upper.begin());
			upper.erase(upper.begin());
		}
	};

	auto total_required = [&](int64_t middle) {
		return (middle * lower.size() - lower_sum) + (upper_sum - middle * upper.size());
	};

	for (int64_t i = 1; i < K; i++)
		increment(A[i]);

	vector<int64_t> sol;
	sol.push_back(total_required(*lower.rbegin()));

	for (int64_t i = K; i < N; i++) {
		if (K == 1) {
			sol.push_back(0);
		} else {
			remove(A[i - K]);
			increment(A[i]);
			sol.push_back(total_required(*lower.rbegin()));
		}
	}

	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}		