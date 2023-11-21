---
Difficulty: "普及/提高−"
tags: ["構造", "羅馬數字"]
---

> Problem: [P1465 [USACO2.2] 序言页码 Preface Numbering](https://www.luogu.com.cn/problem/P1465)

# 思路
- 先構造出羅馬數字，再檢查裡面字符出現的次數

# 解题方法
- 構造方法為使用哈希表一個個數字去找到映射值

# 复杂度
- 时间复杂度:
> $O(N^2)$

- 空间复杂度:
> $O(1)$
  
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

// 檢查是否是回文數、回文串
bool ok(int i)
{
	string s = to_string(i);
	int n = s.size();
	for (int i = 0; i < n; ++i)
		if (s[i] != s[n - 1 - i]) return false;
	return true;
}

string intToRoman(int num) {
	vector<string>str = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	vector<int>nums = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	string res = "";
	int i = nums.size() - 1;
	while (num > 0) {
		if (nums[i] > num)i--;
		else {
			num = num - nums[i];
			res = res + str[i];
		}
	}
	return res;
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, b, d; // 測試用例
	cin >> n;
	vector<string>str = { "I","V","X","L","C","D","M"};
	unordered_map<string, int> mp;
	for (auto s : str) mp[s] = 0;
	for (int i = 1; i <= n; ++i)
	{
		string Roman = intToRoman(i);
		for (auto s : str)
		{
			if (s == Roman)
			{
				mp[s]++;
				continue;
			}
			int res = 0;
			string::size_type pos = 0;
			while ((pos = Roman.find(s, pos)) != std::string::npos)
			{
				res++;
				pos += s.size(); // pos 增加子串長度
			}
			mp[s] += res;
		}
	}
	for (auto ch : str)
	{
		if (mp[ch] == 0) continue;
		cout << ch << " " << mp[ch] << endl;
	}
	return 0;
}
```