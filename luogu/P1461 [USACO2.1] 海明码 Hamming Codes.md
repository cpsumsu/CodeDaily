---
Difficulty: "普及/提高−"
tags: ["枚舉", "二進制"]
---

> Problem: [P1461 [USACO2.1] 海明码 Hamming Codes](https://www.luogu.com.cn/problem/P1461)

# 思路
> 思路比較複雜，核心仍舊為枚舉，使用一個數組去存儲

# 解题方法
> 從 $0$ 開始列舉所有 $2^b$ 個可能的 $b$ 位元二進位編碼，對每個可能的編碼 $i$ ，檢查它與已有的編碼 $buffer[1..idx]$ 的海明距離，使用位元運算計算海明距離 $sum$ ，異或然後統計 $1$ 的個數

# 复杂度
- 时间复杂度:
> $O(2^b)$

- 空间复杂度:
> $O(N)$
  
# Code
```C++ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
// #include <map>
using namespace std;

typedef long long LL;
typedef long long int lli;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x7f7f7f7f; // 最大值2139062143。用於代替INT_MAX 
const int N = 1e5 + 10; // 用於定義常量數組
#define MAXN ((int) 1e5) //
#define MAXM ((int) 1e5)
#define MAXPROD ((int) 1e5)

int moves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 4向移動 順時針

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, b, d;
	cin >> n >> b >> d;
	int idx = 1; // 默認 1 開始
	vector<int> buffer(114514); // 檢查二進制
	cout << "0 "; //從0開始
	// 小到大枚舉
	for (int i = 1; i < (1 << b); ++i)
	{
		// 從0開始列舉所有2^b個可能的b位元二進位編碼
		bool ok = true;
		for (int j = 1; j <= idx; ++j)
		{
			int sum = 0;
			int check = buffer[j] ^ i;
			// 對每個可能的編碼i, 
			// 檢查它與已有的編碼buffer[1..idx]的海明距離
			while (check)
			{
				// 使用位元運算計算海明距離sum,異或然後統計1的個數
				if (check % 2 == 1) sum++;
				check = check >> 1;
			}
			if (sum < d)
			{
				ok = false;
				break;
			}
		}
		// 是否都 >= d。 如果是, 則將i存入buffer
		if (ok)
		{
			if (idx % 10 == 0) cout << endl;
			buffer[++idx] = i;
			cout << i << " ";
		}
		if (n == idx) break;
	}
	return 0;
}
```