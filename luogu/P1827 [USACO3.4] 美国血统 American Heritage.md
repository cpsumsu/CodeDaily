---
Difficulty: "普及−"
tags: ["binary tree"]
---

> Problem: [P1827 [USACO3.4] 美国血统 American Heritage](https://www.luogu.com.cn/problem/P1827)

# 思路
- 用中序遍历和前序遍历還原樹
- 細節看代碼

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

struct Tree
{
	char val;
	Tree* left;
	Tree* right;
	Tree() : val(0), left(nullptr), right(nullptr) {};
	Tree(char v) : val(v), left(nullptr), right(nullptr) {};
	Tree(char v, Tree* left, Tree* right) : val(v), left(left), right(right) {};
};

Tree* buildTree(vector<char> pre, vector<char> in)
{
	if (pre.size() == 0 || in.size() == 0)
		return nullptr;
	// 前綴第一個為根節點
	Tree* root = new Tree(pre[0]);
	for (int i = 0; i < in.size(); ++i)
	{
		// 我們要找到 in[i] == pre[0], pre[0] 通常都出現在 in數組的中間
		if (in[i] == pre[0])
		{
			// 將前序數組分開一半
			// 再將中序數組分開一半
			// 左右部分
			vector<char> l_pre(pre.begin() + 1, pre.begin() + i + 1);
			vector<char> l_in(in.begin(), in.begin() + i);
			vector<char> r_pre(pre.begin() + i + 1, pre.end());
			vector<char> r_in(in.begin() + i + 1, in.end());
			// 再分別處理左邊和右邊部分 
			root->left = buildTree(l_pre, l_in);
			root->right = buildTree(r_pre, r_in);
			break;
		}
	}
	return root;
}

string ans = "";
// post
void post(Tree* root)
{
	if (!root) return;
	post(root->left);
	post(root->right);
	ans += root->val;
}

int main()
{
	// 這裡是加速 cin，如果確定代碼沒有問題但又過不了，可以刪掉
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	string s1, s2;
	cin >> s1 >> s2;
	vector<char> ss1, ss2;
	for (auto ch : s1) ss1.push_back(ch);
	for (auto ch : s2) ss2.push_back(ch);
	Tree* tree = buildTree(ss2, ss1);
	post(tree);
	cout << ans << endl;

	return 0;
}
```