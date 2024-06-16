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
    string ans;
    string tree2str(TreeNode* root) {
        helper(root);
        return ans;
    }

    void helper(TreeNode *cur) {
        if (!cur) return ;

        ans += to_string(cur->val);
        if (cur->left) {
            ans += '(';
            helper(cur->left);
            ans += ')';
        }

        if (cur->right) {
            if (!cur->left)
                ans += "()";
            ans += '(';
            helper(cur->right);
            ans += ')';
        }
    }
};
int main()
{
   return 0;
}