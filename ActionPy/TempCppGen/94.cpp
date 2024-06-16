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
    vector<int> ret;

    void inorder(TreeNode *root) {
        if (!root) return ;
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ret;
    }
};/**
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


class Solution_b {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> sk;

        while (root || sk.size()) {
            while (root) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            ret.push_back(root->val);
            root = root->right; 
        }

        return ret;
    }
};/**
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


class Solution_c {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ret;

        TreeNode *cur = root, *prev;
        while (cur) {
            if (!cur->left) {
                ret.push_back(cur->val);
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right)
                    prev = prev->right;
                prev->right = cur;
                TreeNode *temp = cur;
                cur = cur->left;
                temp->left = nullptr;
            }
        }
        return ret;
    }   
};
int main()
{
   return 0;
}