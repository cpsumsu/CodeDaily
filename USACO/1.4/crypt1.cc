/*
ID: dc22762@um.edu.mo
TASK: crypt1
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
    ifstream in("crypt1.in");
    ofstream out("crypt1.out");

    int N;
    in >> N;

    vector<int> A(N);
    for (auto &x : A)
        in >> x;

    auto three = [](vector<int> &x) -> vector<int> {
        auto a = x, b = x, c = x;

        vector<int> ret;
        for (auto r1 : a)
            for (auto r2 : b)
                for (auto r3 : c)
                    ret.push_back(r1 * 100 + r2 * 10 + r3);

        return ret;
    };

    auto two = [](vector<int> &x) -> vector<int> {
        auto a = x, b = x;

        vector<int> ret;
        for (auto r1 : a)
            for (auto r2 : b)
                ret.push_back(r1 * 10 + r2);

        return ret;
    };

    auto len = [](int x) -> int {
        int ret = 0;
        while (x) x /= 10, ret++;

        return ret;
    };

    set<int> have {A.begin(), A.end()};
    auto check = [&](int x, int n) -> bool {
        if (len(x) != n)
            return false;

        while (x) {
            if (!have.contains(x % 10))
                return false;
            x /= 10;
        }

        return true;
    };

    auto ok = [&](int a, int b) -> bool {
        int b1 = b % 10;
        int b2 = b / 10;

        int m1 = a * b1, m2 = a * b2;
        int m3 = m1 + m2 * 10;

        return check(m1, 3) && check(m2, 3) && check(m3, 4);
    };

    int sol = 0;
    for (auto &a : three(A))
        for (auto &b : two(A))
            if (ok(a, b))
                sol++;

    out << sol << '\n';
}

int main() {

    fastio
    run_case();
}
