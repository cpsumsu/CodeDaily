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

	vector<array<int, 3>> A(N);
	for (int i = 0; i < N; i++) {
		auto &[a, b, no] = A[i];
		cin >> a >> b;
		no = i;
	}

	sort(A.begin(), A.end());
	priority_queue<pair<int, int>> q;

	int last_room = 0, rooms = 0;
	vector<int> sol(N);

	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			last_room++;
			q.push({-A[i][1], last_room});
			sol[A[i][2]] = last_room;
			
		} else {
			auto [left, no] = q.top();

			if (-left >= A[i][0]) {
				last_room++;
				q.push({-A[i][1], last_room});
				sol[A[i][2]] = last_room;

			} else {
				q.pop();
				q.push({-A[i][1], no});
				sol[A[i][2]] = no;
			}
		}

		rooms = max(rooms, (int) q.size());
	}

	cout << rooms << '\n' << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // int tests;
    // cin >> tests;
    // while (tests-- > 0)
		run_case();
    
	return 0;
}