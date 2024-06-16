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

    vector<int> l1, l2;

    void traverse(TreeNode *root, vector<int> &l) {
        if (!root)
            return ;

        if (!root->left && !root->right) {
            l.push_back(root->val);
            return;
        }

        traverse(root->left, l);
        traverse(root->right, l);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverse(root1, l1);
        traverse(root2, l2);

        return l1 == l2;
    }
};