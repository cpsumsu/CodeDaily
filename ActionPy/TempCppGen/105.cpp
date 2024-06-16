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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if (pre.size() == 0 || in.size() == 0)
            return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        for (int i = 0; i < in.size(); ++i)
        {
            if (pre[0] == in[i])
            {
                // 將前序數組分開一半
                // 再將中序數組分開一半
                // 左右部分
                vector<int> l_pre(pre.begin() + 1, pre.begin() + i + 1);
                vector<int> l_in(in.begin(), in.begin() + i);
                vector<int> r_pre(pre.begin() + i + 1, pre.end());
                vector<int> r_in(in.begin() + i + 1, in.end());
                // 再分別處理左邊和右邊部分
                root->left = buildTree(l_pre, l_in);
                root->right = buildTree(r_pre, r_in);
                break;
            }
        }
        return root;
    }
};