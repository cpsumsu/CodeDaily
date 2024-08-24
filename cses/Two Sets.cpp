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


void run_case() {
	int64_t N;
	cin >> N;

	int64_t sum = N * (N + 1) / 2;
	if (sum % 2) {
		cout << "NO" << '\n';
		return ;
	}

	int start = (N % 4) ? 3 : 4;
	vector<int> v1, v2;

	for (int i = 0; i < (N - 1) / 4; i++) {
		v1.push_back(4 * i + 1 + start);
		v1.push_back(4 * i + 4 + start);
		v2.push_back(4 * i + 2 + start);
		v2.push_back(4 * i + 3 + start);
	}

	if (start == 3) {
		v1.push_back(1);
		v1.push_back(2);
		v2.push_back(3);
	} else {
		v1.push_back(1);
		v1.push_back(4);
		v2.push_back(2);
		v2.push_back(3);
	}

	cout << "YES" << '\n';
	cout << v1.size() << '\n' << v1 << '\n';
	cout << v2.size() << '\n' << v2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}