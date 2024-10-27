# Fence Loops

[question](https://usaco.training/usacoprob2?a=8cvqq0t1jHZ&S=nuggets) or search it in [luogu](https://www.luogu.com.cn/problem/P2737)

My first impression to this question is dp. But it is quite tough to calculate a maximum number with 2e9 without TLE. So, what we can do is to prove that it has a upperbound (must less than 2e9) if the upperbound exists. Using dp, we don't concern about whether the upperbound exist or not since if we cannot find it within [1, upperbound], then returns the largest value that fulfill the requirment.

However, we can determine the existence of upperbound with gcd. And determine the exact value of upperbound using concept of gcd and lcm :) interesting!

# example

Consider the packaging option i within [1, 5]. Given that the number of nuggests in kind of box: 3, 5
lcm(5, 3) = 15
gcd(5, 3) = 1

it satisfies 3, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20......

What happen is that after lcm, the next value must be lcm + gcd * k, k is constant. Therefore, consider gcd is next step after lcm. if gcd is 1, then all the value must be included after lcm. If not, ther msut be lcm + gcd * n < A < lcm + gcd * (n + 1). A is the next largest value that fulfill the requirement. In this case, we cannot find the largest value.

lcm is the upperbound that we need to traverse. if the gcd is 1, we use dp to check which is the largest value that fulfill the requirment.

# solution

check gcd

```cpp
int N;
cin >> N;

vector<int> A(N);

for (auto &x : A)
    cin >> x;

int g = A[0];
for (int i = 1; i < A.size(); i++)
    g = gcd(g, A[i]);

// gcd != 1 means cannot cover each number after lcm
if (g != 1) {
    cout << 0 << '\n';
    return ;
}
```

since the volume of nuggets box within [1, 256] (given in question). So the upperbound is 255 * 256 (consider the inputs include 255, 256). OK, you might ask why not 256 * 255 * 245 * .... Consider that given 256, 255, 254. the first upperbound of 255 and 254 is 255 * 254, second upperbound is 256 * 255. The latter one larger than former one!

Moreover, consider that the first example, volume within [1, 5], given 3, 5. The actually upperbound is 3 * 5. However, we are not sure the input, so find the maximum upperbound (4 * 5) !

```cpp
const int range = 256 * 255

vector<bool> dp(range + 256);
dp[0] = true;
int largest = 0;

for (int i = 0; i < range + 1; i++) {
    if (dp[i]) {
        for (auto x : A)
            dp[i + x] = true;
    } else {
        largest = i;
    }
}

cout << largest << '\n';
```

# complete code

```cpp
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

// gcd is the step walk after lcm. if gcd != 1, which means there must be lcm + gcd * n < k < lcm + gcd * (n + 1)
void run_case() {
    // the largest lcm
    const int range = 256 * 255;

    int N;
    cin >> N;

    vector<int> A(N);

    for (auto &x : A)
        cin >> x;

    int g = A[0];
    for (int i = 1; i < A.size(); i++)
        g = gcd(g, A[i]);

    // gcd != 1 means cannot cover each number after lcm
    if (g != 1) {
        cout << 0 << '\n';
        return ;
    }

    vector<bool> dp(range + 256);
    dp[0] = true;
    int largest = 0;

    for (int i = 0; i < range + 1; i++) {
        if (dp[i]) {
            for (auto x : A)
                dp[i + x] = true;
        } else {
            largest = i;
        }
    }

    cout << largest << '\n';
}

int main() {
    fastio
    run_case();
}

```
