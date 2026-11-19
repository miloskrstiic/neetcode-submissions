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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* right = &dummy;
        ListNode* left = &dummy;
        int helper = n;
        while (right != nullptr && helper > 0) {
            right = right->next;
            helper--;
        }

        while (right->next != nullptr) {
            right = right->next;
            left = left->next;
        }
        
        left->next = left->next->next;
        return dummy.next;
    }
};
