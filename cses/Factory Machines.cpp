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

// // TLE
// void run_case() {
// 	int N, T;
// 	cin >> N >> T;

// 	vector<int> A(N);
// 	for (auto &x : A)
// 		cin >> x;

// 	int cnt = 0, time = 0;
// 	while (cnt < T) {
// 		time++;

// 		for (auto &x : A) 
// 			if (time % x == 0)
// 				cnt++;
// 	}

// 	cout << time << '\n';
// }

void run_case() {
	int64_t N, T;
	cin >> N >> T;
	vector<int64_t> A(N);

	for (auto &x : A)
		cin >> x;

	auto enough = [&](int64_t time) -> bool {
		int64_t sum = 0;

		for (auto &x : A) {
			sum += time / x;

			if (sum >= T)
				return true;
		}

		return false;
	};

	int64_t lo = 0, hi = 1e18, sol = 0;

	while (lo <= hi) {
		int64_t mid = lo + (hi - lo) / 2;

		if (enough(mid)) {
			sol = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}

		// dbug_out(hi, lo);
	}

	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}