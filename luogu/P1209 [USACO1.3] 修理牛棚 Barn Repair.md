---
Difficulty: "普及/提高−"
tags: ["Greedy"]
---

> Problem: [P1209 [USACO1.3] 修理牛棚 Barn Repair](https://www.luogu.com.cn/problem/P1209)

# 思路
> 先排序，然後就可以算牛之間的距離
> 
> 再排序剛剛的距離，一共斷開 m - 1 個距離(從idx大到小)，那就可以取最小的距離了

# 复杂度
- 时间复杂度:
> $O(c * m * \text{log}n)$

- 空间复杂度:
> $O(1)$
  

# Code
```C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

typedef long long LL;
typedef long long int lli;
typedef unsigned long long ull;
lli var1, var2;
#define rep(i, l, u) for (lli i = l; i <= u; i++)

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int m, s, c;
	cin >> m >> s >> c;
	int cow[255], len[255];
	for (int i = 1; i <= c; ++i)
	{
		cin >> cow[i];
	}
	if (m >= c)
	{
		printf("%d\n", c);
		return 0;
	}
	sort(cow + 1, cow + c + 1); // 小到大
	for (int i = 1; i <= c; ++i)
	{
		len[i] = cow[i + 1] - cow[i] - 1; // 牛之間的距離
	}
	sort(len + 1, len + c, [](auto a, auto b) {return a > b; });
	int ans = cow[c] - cow[1] + 1;
	for (int i = 1; i <= m - 1; ++i) 
		ans -= len[i]; // 一共斷開 m - 1 個距離(從idx大到小
	printf("%d\n", ans);
	return 0;
}

c++17 版本的代碼, 有點改動

```cppsd
#include <bits/stdc++.h>

void main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(K);
    for (auto &x : A)
        cin >> x;

    vector<int> diff(K - 1);
    for (int i = 1; i < K; i++) 
        diff[i - 1] = A[i] - A[i - 1];

    int total = A.back() - A.front() + 1; 		// 記得加1！
    sort(diff.begin(), diff.end(), greater<int>());

    for (int i = 0; i < N - 1; i++)
        total = total - diff[i] + 1;		// 下述的方法有說明為何 +1

    cout << total << '\n';
}

```

一個低效的方法。。。
- 類似上述的方法，不過題目沒提到一個牛棚是否只能裝下一隻牛，而且也不確定輸入是否會順序，所以需要另一個容器 B 裝著輸入 
- 相比于 `cow[c] - cow[1] + 1` 這種直接得到總長，以下的那種把所有的牛之間的距離加總，不過這方法需要另外算斷開後加上的 extra 
例如
牛棚索引： 0 1 2 3 4 5 6
假設每個牛棚之間的距離是 1， 
1. 那麼 1 到 2 之間的距離是 (2 - 1) + 1， 4 到 6 之間的距離是 （4 - 6）＋ 1， 總共是 5
2. 但連續的牛棚從 1 到 5 ＝ （5 - 1）＋ 1 也是 5
**那麼每一個斷開都需要加上一個 extra （例1）加了 2， （例2）加了 1**

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

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(K);
    for (auto &x : A)    
        cin >> x;

    sort(A.begin(), A.end());
    vector<int> B = {A.begin(), unique(A.begin(), A.end())};

    vector<int> diff(B.size() - 1);

    for (int i = 1; i < B.size(); i++)
        diff[i - 1] = B[i] - B[i - 1];

    sort(diff.begin(), diff.end(), greater<int>());
    int t = N - 1;

    int sum = accumulate(diff.begin(), diff.end(), 0), extra = 1, removed = 0;
    int sol = 1e9;

    for (int i = 0; i < diff.size() && t--; i++) {
        if (sol > sum - removed + extra) {
            sol = sum - removed + extra;
            extra++;
        }

        removed += diff[i];
    }

    sol = min(sol, sum - removed + extra);

    cout << sol << '\n';
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```