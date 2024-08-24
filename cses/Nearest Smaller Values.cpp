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
// 	int N;
// 	cin >> N;
// 	vector<array<int, 2>> A(N);

// 	for (int i = 0; i < N; i++) {
// 		auto &[a, b] = A[i];
// 		cin >> a;
// 		b = i;
// 	}	

// 	stable_sort(A.begin(), A.end());
// 	dbug_out(A);
// 	vector<int> sol(N, -1);
// 	int min_required = A.front()[1];

// 	set<int> s;

// 	for (int i = 0; i < N; i++) {
// 		if (i == 0) continue;

// 		if (A[i][1] < min_required) {
// 			min_required = min(min_required, A[i][1]);
// 			continue;
// 		}

// 	}

// 	for (auto &x : sol)
// 		if (x != -1)
// 			cout << x + 1 << ' ';
// 		else
// 			cout << 0 << ' ';
// }

void run_case() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto &x : A)
		cin >> x;

	priority_queue<array<int, 2>> pq;
	pq.push({0, A.front()});
	vector<int> sol(N);

	for (int i = 1; i < N; i++) {
		while (pq.size() && A[i] <= pq.top()[1])
			pq.pop();

		if (pq.size())
			sol[i] = pq.top()[0] + 1;

		pq.push({i, A[i]});
	}

	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	run_case();
    
	return 0;
}