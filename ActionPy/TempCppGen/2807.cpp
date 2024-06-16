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
    int gcd(int a, int b)
    {
        return a % b == 0 ? b : gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == NULL) return head;
        ListNode* p = head;
        while(p->next)
        {
            ListNode* b = p->next;
            ListNode* o = new ListNode(gcd(p->val, b->val));
            p->next = o;
            o->next = b;
            p = b;
        }
        return head;
    }
};
int main()
{
   return 0;
}