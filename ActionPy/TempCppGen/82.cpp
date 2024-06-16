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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode(0, head);
        ListNode* pre = ans;
        ListNode* p = head;
        while(p)
        {
            while(p->next && p->next->val == p->val)
                p = p->next;
            if (pre->next == p)
                pre = p;
            else
                pre->next = p->next;
            p = p->next;
        }
        return ans->next;
    }
};/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution_b {
public:
    
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* n = head->next;
        if (head->val == n->val)
        {
            while (n != nullptr && head->val == n->val)
            {
                n = n->next;
            }
            head = deleteDuplicates(n);
        }
        else
        {
            head->next = deleteDuplicates(n);
        }
        return head;
    }
};