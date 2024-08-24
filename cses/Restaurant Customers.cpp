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

struct customer {
	int val;
	bool is_in;
};

void run_case() {
	int N;
	cin >> N;

	vector<customer> A(N * 2);
	for (int i = 0; i < N * 2; i++) {
		int a, b;
		cin >> a >> b;
		A[i].val = a;
		A[i].is_in = true;
		i++;
		A[i].val = b;
		A[i].is_in = false;
	}

	sort(A.begin(), A.end(), [](const customer &x, const customer &y) {
		return x.val < y.val;
	});

	int sol = 0, ans = 0;
	for (int i = 0; i < N * 2; i++) {
		auto [x, y] = A[i];

		if (y)
			sol++;
		else
			sol--;

		ans = max(ans, sol);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}