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
	int N;
	cin >> N;

	vector<int> contains(N), contained(N);
	vector<array<int, 3>> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i][0] >> A[i][1];
		A[i][2] = i;
	}

	sort(A.begin(), A.end(), [](auto &a, auto &b) {
		return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
	});

	dbug_out(A);

	int max_end = -1e9 + 7;
	for (int i = 0; i < N; i++) {
		if (A[i][1] <= max_end) {
			contained[A[i][2]] = 1;
		} else {
			max_end = A[i][1];
		}
	}

	int min_end = 1e9 + 7;
	for (int i = N - 1; i >= 0; i--) {
		if (A[i][1] >= min_end)
			contains[A[i][2]] = 1;
		else
			min_end = A[i][1];

	}

	cout << contains << '\n' << contained << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}