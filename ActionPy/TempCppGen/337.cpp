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
    pair<int,int> dfs(TreeNode* root)
    {
        if (root == nullptr) return {0,0};
        auto [l, l_not] = dfs(root->left);
        auto [r, r_not] = dfs(root->right);
        int rob = root->val + l_not + r_not;
        int n_rob = max(l, l_not) + max(r, r_not);
        return {rob, n_rob};
    }

    int rob(TreeNode* root) {
        auto [a,b] = dfs(root);
        return max(a,b);
    }
};
int main()
{
   return 0;
}