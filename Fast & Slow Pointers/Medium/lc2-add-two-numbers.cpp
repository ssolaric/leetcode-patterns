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
    ListNode* add(ListNode* tail, int val) {
        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        return newNode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* tail = dummy;
        
        while (l1 || l2 || carry > 0) {
            int sumDigits = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sumDigits / 10;
            int digit = sumDigits % 10;
            tail = add(tail, digit);
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        return dummy->next;
    }
};