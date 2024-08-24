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
	int X, N;
	cin >> X >> N;

	set<int> s {0, X};
	multiset<int> ms {X};

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		auto next = s.upper_bound(a);
		auto previous = prev(next);


		if (auto remove = ms.find(*next - *previous); remove != ms.end())
			ms.erase(remove);

		ms.insert(a - *previous);
		ms.insert(*next - a);

		s.insert(a);
		cout << *prev(ms.end()) << " \n"[i == N - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

 	run_case();   

    return 0;
}

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	int street_len;
// 	int light_num;
// 	cin >> street_len >> light_num;

// 	set<int> lights{0, street_len};
// 	multiset<int> dist{street_len};
// 	for (int l = 0; l < light_num; l++) {
// 		int pos;
// 		cin >> pos;

// 		auto it1 = lights.upper_bound(pos);
// 		auto it2 = it1;
// 		--it2;


// 		dist.erase(dist.find(*it1 - *it2));
// 		println("dist: ", dist);
// 		dist.insert(pos - *it2);
// 		dist.insert(*it1 - pos);
// 		lights.insert(pos);

// 		auto ans = dist.end();
// 		--ans;
// 		cout << *ans << " ";
// 	}
// }

