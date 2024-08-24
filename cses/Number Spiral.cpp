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


// we discover that if the largest number is 3, say input is (2, 3). Then, the output must be within [4, 9] -- the third layer. 
// diff = outter layer - inner layer, add the min_val control the position, rmb to minus 1.
// However, due to the spiral feature, we have no idea if we start walking from the largest or smallest value in that layer. For example, in 3rd layer, (3, 0) = 16 or 10? (0, 3) == 16 or 10?
// But we discover that odd nunber rows on y-asix direction have the largest number in that layer. even number rows on x-asix direction have the largest number in that layer

// Example: (2, 3), the max_val = 3, so that number must be within [5, 9]. Since the max_val is Y, so observe the X-axis direction. we discover that 
// the row is located at 3rd and value 9 is the largest value in that layer. So use formual (Y * Y) - (X - 1) = 3 * 3 - (2 - 1). where (Y * Y) determine 
// the largest value in 3rd layer, (X - 1) locate the position.

// Moreover, since we might meet query like (2, 4), which ans is 11. max_val == Y and 4th start
// with the smallest value (10). we start from 10 and walk 1 step to 11. we need to know the minimum value in that smallest value in that layer. 
// therefore, (outter - (outter - inner)) to find smallest value. Then add back (min_val - 1)

// In conclusino, we just need to know which is the outter layer (by finding the largest number) and determine start walking from largest value or smallest 
// value in that layer.

void run_case() {
	int64_t X, Y;
	cin >> X >> Y;

	int64_t max_val = max(X, Y), min_val = min(X, Y);
	bool odd = max_val & 1;
	int64_t ans = 0;

	if (max_val == X) {
		if (!odd)
			ans = max_val * max_val - (min_val - 1);
		else {
			int64_t outter = max_val * max_val;
			int64_t inner = (max_val - 1) * (max_val - 1);
			ans = outter - (outter - inner) + min_val;

		}
	} else if (max_val == Y) {
		if (odd) {
			ans = max_val * max_val - (min_val - 1);
		} else {
			int64_t outter = max_val * max_val;
			int64_t inner = (max_val - 1) * (max_val - 1);
			ans = outter - (outter - inner) + min_val;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tests;
    cin >> tests;
    while (tests--)
	 	run_case();   

    return 0;
}