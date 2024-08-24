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
	int N, T;
	cin >> N >> T;
	vector<int> A(N);

	dbug_out("yo");

	for (auto &x : A)	
		cin >> x;

	int window_sum = A.front(), sol = 0;

	for (int i = 0, j = 1; i <= j && j <= N; i++) {
		if (i > 0)
			window_sum -= A[i - 1];

		if (window_sum == T) {
			sol++;
			continue;
		}

		while (window_sum < T && j < N) {
			dbug_out(A[j], window_sum);
			window_sum += A[j++];
			dbug_out(window_sum);

			if (window_sum == T) {
				dbug_out(window_sum, T);
				sol++;
				dbug_out(window_sum);
				break;
			}
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