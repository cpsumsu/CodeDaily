#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution_a {
public:
    vector<int> ans;
    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        int n = ans.size();
        vector<vector<int>> res;
        for (auto q : queries)
        {
            int idx = ranges::lower_bound(ans, q) - ans.begin();
            int mx = -1, mn = -1;
            if (idx < n) mx = ans[idx];
            if (idx == n || ans[idx] != q) idx--;
            if (idx >= 0) mn = ans[idx];
            res.push_back({mn, mx});
        }
        return res;
    }
};
int main()
{
   return 0;
}