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
	int64_t N, K;
	cin >> N >> K;

	auto get_sum = [](int64_t start, int64_t n) {
		return start * n + n * (n - 1) / 2;
	};

	auto compute_diff = [&](int64_t prefix) {
		return get_sum(K, prefix) - get_sum(K + prefix, N - prefix);
	};

	int mid = 0;

	for (int b = N; b >= 1; b /= 2) {
		while (b + mid < N && compute_diff(b + mid) <= 0)
			mid += b;
	}

	cout << min(abs(compute_diff(mid + 1)), abs(compute_diff(mid))) << '\n';
}

int main() {
	fastio

    int tests;
    cin >> tests;
    while (tests-- > 0)
		run_case();
    
	return 0;
}