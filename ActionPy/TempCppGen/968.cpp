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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution_a {
public:
    int minCameraCover(TreeNode* root) {
        function<tuple<int, int, int>(TreeNode*)> dfs = [&](TreeNode* root) ->tuple<int, int, int> {
            if (root == nullptr) return {INT_MAX / 2,0,0};
            auto [l_select, l_fa, l_children] = dfs(root->left);
            auto [r_select, r_fa, r_children] = dfs(root->right);
            int select = min(l_select, l_fa) + min(r_select, r_fa) + 1;
            int fa = min(l_select, l_children) + min(r_select, r_children);
            int children = min({l_select + r_children, r_select + l_children, l_select + r_select});
            return {select, fa, children};
        };
        auto [a, b, c] = dfs(root);
        return min(a, c);

    }
};
int main()
{
   return 0;
}