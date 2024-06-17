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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution_a {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> L;
        stack<int> st;
        ListNode* p = head;
        while(p)
        {
            L.push_back(p->val);
            p = p->next;
        }
        int n = L.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            while(!st.empty() && L[st.top()] <= L[i])
                st.pop();
            if (!st.empty())
                ans[i] = L[st.top()];
            st.push(i);
        }
        return ans;
    }
};
int main()
{
   return 0;
}