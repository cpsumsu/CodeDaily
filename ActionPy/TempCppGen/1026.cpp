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
    void dfs(TreeNode*root, int ma, int mi)
    {
        if (root == nullptr){
            return;
        }
        ma = max(ma, root->val);
        mi = min(mi, root->val);
        dfs(root->left, ma, mi);
        dfs(root->right, ma, mi);
        ans = max(ans, ma - mi);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        dfs(root, root->val, root->val);
        return ans;
    }
};