#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits.h>
#include <unordered_set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <string.h>
#include <numeric>
#include <cassert>
#include <cmath>
#include <cstdint>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty())
        {
            return nullptr;
        }
        if (preorder.size() == 1)
        {
            return new TreeNode(preorder[0]);
        }
        // 
        int i = ranges::find(postorder, preorder[1]) - postorder.begin() + 1;
        vector<int> prel(preorder.begin() + 1, preorder.begin() + 1 + i);
        vector<int> prer(preorder.begin() + 1 + i, preorder.end());
        // 不+1，排除[0]
        vector<int> post1(postorder.begin(), postorder.begin() + i); 
        vector<int> postr(postorder.begin() + i, postorder.end() - 1);
        TreeNode* l = constructFromPrePost(prel, post1);
        TreeNode* r = constructFromPrePost(prer, postr);
        return new TreeNode(preorder[0], l, r);
    }
};
int main()
{
   return 0;
}