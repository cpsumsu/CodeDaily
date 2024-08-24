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

void run_case() {
	int64_t N, T;
	cin >> N >> T;
	vector<array<int64_t, 2>> A(N);

	for (int64_t i = 0; i < N; i++) {
		auto &[a, b] = A[i];
		cin >> a;
		b = i + 1;
	}

	sort(A.begin(), A.end());

	for (int64_t i = 0; i < N - 3; i++) {
		int64_t three = T - A[i][0];

		for (int64_t j = i + 1; j < N - 2; j++) {
			int64_t two = three - A[j][0];

			int64_t lo = j + 1, hi = N - 1;
			while (lo < hi) {
				int64_t compare = A[lo][0] + A[hi][0] - two;

				if (!compare) {
					cout << A[i][1] << ' ' << A[j][1] << ' ' << A[lo][1] << ' ' << A[hi][1] << '\n';
					dbug_out(A[i][0], A[j][0], A[lo][0], A[hi][0]);
					return ;
				}

				if (compare < 0)
					lo++;
				else
					hi--;
			}
		}
	}

	cout << "IMPOSSIBLE" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}