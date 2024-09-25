/*
ID: dc22762@um.edu.mo
TASK: milk2
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

void run_case() {
    ifstream in("milk2.in");
    ofstream out("milk2.out");

    int N;
    in >> N;

    vector<pair<int, int>> intervals(N);
    for (auto &[a, b] : intervals)
    	in >> a >> b;

    sort(intervals.begin(), intervals.end());

    int minimum = intervals[0].first, maximum = intervals[0].second;
    int longest_unmilked = 0, longest_milked = 0;

    for (int i = 1; i < N; i++) {
    	if (maximum < intervals[i].first) {
    		longest_milked = max(longest_milked, maximum - minimum);
    		longest_unmilked = max(longest_unmilked, intervals[i].first - maximum);
    		maximum = intervals[i].second;
    		minimum = intervals[i].first;
    	}

    	maximum = max(maximum, intervals[i].second);
    }

    longest_milked = max(longest_milked, maximum - minimum);

    out << longest_milked << ' ' << longest_unmilked << '\n';
}

int main() {
    fastio
    run_case();
}
