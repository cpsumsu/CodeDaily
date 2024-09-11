---
Difficulty: "普及+/提高"
tags: ["枚舉"]
---

> Problem: [P1214 [USACO1.4] 等差数列 Arithmetic Progressions](https://www.luogu.com.cn/problem/P1214)

# 思路
> 枚舉 $k = b + d$ 到 $a + (n - 1) * d$
>
> 然後 $a$ 枚舉到 $250 * 2$
>
> $b$ 也是從 $a$ 到 $250 * 2$

# 复杂度
- 时间复杂度:
> $O(n ^ 2 \text{log} n)$

- 空间复杂度:
> $O(n^2)$
  

# Code
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long LL;
typedef long long int lli;
typedef unsigned long long ull;
lli var1, var2;
#define rep(i, l, u) for (lli i = l; i <= u; i++)


// 用 unordered_map 存儲所有可能 O(n^2)
unordered_map<int, bool> mp;
void initm(int m)
{
	int p, q;
	for (p = 0; p <= m; ++p)
		for (q = 0; q <= m; ++q)
			mp[p * p + q * q] = true;
}

bool isok(int a, int b, int d, int n)
{
	// 這裡改成枚舉 k = b + d
	for (int k = b + d; k <= a + (n - 1) * d; k += d)
		if (!mp[k]) return false;
	return true;
}



int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, m;
	cin >> n >> m;
	int mx = m * m << 1; // 250^2 * 2
	initm(m);
	vector<vector<int>> ans;
	for (int a = 0; a <= mx; a++)
	{
		if (mp[a])
			for (int b = a+1; b <= mx; b++)
			{
				if (mp[b])
				{
					int dd = b - a;
					if (a + (n - 1) * dd > mx) break;
					if (isok(a, b, dd,n)) 
						ans.push_back({ a,dd });
				}
			}
	}
		
	if (ans.size() == 0) cout << "NONE" << endl;
	else
	{
		sort(ans.begin(), ans.end(), [](auto a, auto b)
			{
				if (a[1] == b[1]) return a[0] < b[0];
				return a[1] < b[1];
			});
		for (auto a : ans)
			cout << a[0] << " " << a[1] << endl;
	}
	return 0;
}
```


本題明顯是暴力枚舉！（因為數值少，m 只有 250) 

額外補充，這題的黑魔法比較多，上述符合需求的 b 變量只可能是 4 的倍數當 a >= 4, [証明](https://www.luogu.com.cn/problem/solution/P1214)詳細請看。另外，因為 m 比較少 (1 <= m <= 250)，所以用桶算法會比 unordered_map 快



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
    int N, M;
    cin >> N >> M;

    // 0 <= a^2 + b^2 <= maximum 
    int maximum = M * M * 2;
    vector<bool> bucket(maximum + 1, false);

    // use bucket to record p^2 + q^2
    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= M; j++)
            bucket[i * i + j * j] = true;

    vector<pair<int, int>> sol;
    for (int i = 0; i <= maximum; i++) {
        if (!bucket[i])
            continue;

        for (int j = i + 1; j <= maximum; j++) {
        	// b = diff
            int diff = j - i;

            // *********黑魔法！但不用也可以通過**************
            if (i >= 4 && diff % 4 != 0)
            	continue;
            // ******************************************

            int maxi = i + (N - 1) * diff;

            if (maxi > maximum)
                break;

 			// check whether all the elements of Arithmetic progression in set p^2 + q^2
            bool valid = true;
            for (int x = i + diff; x <= maxi; x += diff)
                if (!bucket[x]) {
                    valid = false;
                    break;
                }

            if (valid)
                sol.emplace_back(i, diff);
        }
    }

    sort(sol.begin(), sol.end(), [](auto &a, auto &b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    if (sol.empty()) {
        cout << "NONE" << '\n';
        return ;
    }

    for (auto &x : sol)
        cout << x.first << ' ' << x.second << '\n';
}

int main() {
    fastio
    
    run_case();
    
    return 0;
}
```