#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
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
    // previous choices: L : True, R: False 
    void dfs(TreeNode* root, bool LR, int d)
    {
        if (root == nullptr) return;
        d++;
        ans = max(ans, d);
        if (LR)
        {
            dfs(root->right, false, d);
            dfs(root->left, true, 0);
        }
        else
        {
            dfs(root->right, false, 0);
            dfs(root->left, true, d);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root->right, false, 0);
        dfs(root->left, true, 0);
        return ans;
    }
};
int main()
{
   return 0;
}