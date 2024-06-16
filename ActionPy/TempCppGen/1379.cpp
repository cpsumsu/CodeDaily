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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



class Solution_a {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target || original == nullptr)
            return cloned;
        auto l = getTargetCopy(original->left, cloned->left, target);
        auto r = getTargetCopy(original->right, cloned->right, target);
        if (l) return l;
        if (r) return r;
        return r;
    }
};
int main()
{
   return 0;
}