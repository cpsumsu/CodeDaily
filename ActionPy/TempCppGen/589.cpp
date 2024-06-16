#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/



class Solution_a {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            Node* F = q.top(); q.pop();
            ans.push_back(F->val);
            for (int i = F->children.size() - 1; i >= 0 ; --i) 
                if (F->children[i]) q.push(F->children[i]);
        }
        return ans;
    }
};
int main()
{
   return 0;
}