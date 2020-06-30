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
        ListNode* cur = head;
        for (int i = 0; i < n; i++) {
            cur = cur->next;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* toRemove = head;
        while (cur != nullptr) {
            cur = cur->next;
            prev = toRemove;
            toRemove = toRemove->next;
        }
        prev->next = toRemove->next;
        return dummy->next;
    }
};