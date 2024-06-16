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
    char str[12] = "00000000000";
    int ans = 0;
    void cstr(int i)
    {
        if (str[i] == '0') str[i] = '1';
        else str[i] = '0';
    }
    void isok()
    {
        bool fg = false;
        for (int i = 1; i <= 9; ++i)
        {
            int j = str[i] - '0';
            if (j && fg) return;
            if (j && !fg) fg = true;
        }
        ans++;
    }
    void dfs(TreeNode* root)
    {
        if (!root->left && !root->right) isok();
        if (root->right)
        {
            int i = root->right->val;
            cstr(i);
            dfs(root->right);
            cstr(i);
        }
        if (root->left)
        {
            int i = root->left->val;
            cstr(i);
            dfs(root->left);
            cstr(i);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        cstr(root->val);
        dfs(root);
        return ans;
    }
};
int main()
{
   return 0;
}