---
Difficulty: "普及−"
tags: ["素数判断,质数,筛法"]
---

> Problem: [P1217 [USACO1.5] 回文质数 Prime Palindromes](https://www.luogu.com.cn/problem/P1217)

# 思路
- 這題難點在於如何不超時的情況下找出所有這種的數，判斷回文質數需要過兩項檢查 （檢查回文 O(N)，檢查質數 O(?))
- 查出質數可以用 sieve 方法 （查看 generate_prime，基礎，不作解釋)
- 查出回文方法有很多, 超簡單的有

```cpp
bool is_palidrome(int x) {
	string A = to_string(x);
	string B = A;

	reverse(B.begin(), B.end());
	return A == B;

	// // more concise
	// string A = to_string(x);
	// return A == {A.rbegin(), A.rend()};
} 
```

- 但是，a,b 範圍頗大 (5≤a<b≤100,000,000), 因此我們需要一個方法找出確定不是的數。[大佬](https://www.luogu.com.cn/problem/solution/P1217) 解釋的很清楚。總結，偶數位的回文質數只有 11 (因為其他的都是 11 的倍數, 例如 7337 = 11 * 667, 9339 = 11 * 849)， 因此可以用 (check_digits) 來移除一半以上的選項


# Code
```cpp
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

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

vector<bool> generate_prime(int64_t maximum) {
    vector<bool> sieve(maximum + 1, true);

    sieve[0] = sieve[1] = false;

    for (int64_t i = 2; i <= maximum; i++) {
        if (sieve[i]) {
            for (int64_t j = i * i; j <= maximum; j += i)
                if (sieve[j])
                    sieve[j] = false;
        }
    }

    return sieve;
}

bool check_digit(int64_t x) {
    if ((1000LL <= x && x <= 9999LL) || (100000LL <= x && x <= 999999LL))
        return false;

    return true;
}

bool is_palidrome(int64_t x) {
    auto str = to_string(x);

    for (int64_t i = 0, j = str.size() - 1; i <= j; i++, j--)
        if (str[i] != str[j])
            return false;

    return true;
}

void run_case() {
    int64_t l, r;
    cin >> l >> r;

    l = (l % 2 == 0) ? l + 1 : l;
    r = min(INT64_C(9999999), r);

    auto primes = generate_prime(r);

    for (int64_t x = l; x <= r; x += 2) {
        if (check_digit(x) && primes[x] && is_palidrome(x))
            cout << x << '\n';
    }
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```
