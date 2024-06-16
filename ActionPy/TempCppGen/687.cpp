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
    int ans = 0;
    int dfs(TreeNode* root)
    {
        if (root == nullptr) return -1;
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        if (root->left && root->left->val != root->val) l = 0;
        if (root->right && root->right->val != root->val) r = 0;
        ans = max(ans, l + r);
        
        return max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};