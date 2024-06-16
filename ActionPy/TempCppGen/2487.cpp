#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
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
    ListNode* removeNodes(ListNode* head) {
        ListNode* node = head;
        stack<ListNode*> st;
        while(node)
        {
            while(!st.empty() && node->val > st.top()->val)
                st.pop();
            if (st.empty())
                head = node;
            else
                st.top()->next = node;
            st.push(node);
            node = node->next;
        }
        return head;
    }
};