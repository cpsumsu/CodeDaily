/*
ID: dc22762@um.edu.mo
TASK: transform
LANG: C++20
*/
#include <iostream>
#include <climits>
#include <vector>
#include <array>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <cassert>
#include <cstdint>
#include <fstream>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

template <class F>
struct y_combinator {
    F f;
    template <class... Args>
    decltype(auto) operator()(Args&&... args) const { return f(*this, std::forward<Args>(args)...); }
};
template <class F> y_combinator<std::decay_t<F>> make_y_combinator(F&& f) { return {std::forward<F>(f)}; }

template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = enable_if_t<!is_same_v<T_container, string>, typename T_container::value_type>> ostream &operator<<(ostream &os, const T_container &arg) { os << '{'; string sep; for (const T &x : arg) os << sep << x, sep = ", "; return os << '}'; }

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

/*
0 0 -> 0 2
0 1 -> 1 2
0 2 -> 2 2
1 0 -> 0 1
1 1 -> 1 1
1 2 -> 2 1
2 0 -> 0 0
2 1 -> 1 0
2 2 -> 2 0
*/

void run_case() {
    ifstream in("transform.in");
    ofstream out("transform.out");

  	int N;
  	in >> N;
  	vector<string> pattern(N);

  	for (auto &x : pattern)
  		in >> x;

  	vector<string> transform(N);
  	for (auto &x : transform)
  		in >> x;

  	vector<string> original = pattern;

  	auto rotate = [&](vector<string> &v, int times) -> void {
  		auto copy = v;

  		while (times--)
	  		for (int i = 0; i < N; i++)
	  			for (int j = 0; j < N; j++)
	  				v[j][N - i - 1] = copy[i][j];
  	};

  	for (int i = 0; i < 3; i++) {
  		rotate(pattern, 1);

  		if (pattern == transform) {
  			out << i + 1 << '\n';
  			return ;
  		}
  	}

  	pattern = original;

  	for (int i = 0; i < N; i++)
  		for (int j = 0; j < N; j++)
  			pattern[i][j] = original[i][N - j - 1];

  	if (pattern == transform) {
  		out << 4 << '\n';
  		return ;
  	}

  	for (int i = 0; i < 3; i++) {
  		rotate(pattern, 1);

  		if (pattern == transform) {
  			out << 5 << '\n';
  			return ;
  		}
  	}

  	if (original == transform) {
  		out << 6 << '\n';
  		return ;
  	}

  	out << 7 << '\n';
}

int main() {
    fastio
    run_case();
}
