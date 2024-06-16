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
    vector<TreeNode*> allPossibleFBT(int n) {
        // 偶數返回空
        if (n % 2 == 0) 
            return {};
        // n = 1 時只返回一個節點
        if (n == 1) 
            return {new TreeNode(0)};
        vector<TreeNode*> dp;
        for (int i = 1; i <= n - 2; i += 2)
        {
            vector<TreeNode*> l = allPossibleFBT(i);
            vector<TreeNode*> r = allPossibleFBT(n - 1 - i);
            // 排列組合 l.size() * r.size()
            for (int i = 0; i < l.size(); ++i)
                for (int j = 0; j < r.size(); ++j)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = l[i];
                    root->right = r[j];
                    dp.push_back(root);
                }
        }
        return dp;
    }
};