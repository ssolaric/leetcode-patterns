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
    // Returns the head and the tail of the reversed list.
    pair<ListNode*, ListNode*> reverse(ListNode* head, int length) {
        ListNode* tail = head;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        for (int i = 0; i < length && cur != nullptr; i++) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        tail->next = cur;
        return {prev, tail};
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        int pos = 1;
        while (cur != nullptr) {
            if (pos == m) {
                auto [newHead, tail] = reverse(cur, n - m + 1);
                prev->next = newHead;
                prev = tail;
                cur = tail->next;
                pos = n + 1;
            }
            else {
                prev = cur;
                cur = cur->next;
                pos++;
            }
        }
        
        return dummy->next;
    }
};