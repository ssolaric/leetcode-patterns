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
    // Returns the head and the tail of the list in reverse
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
    
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        while (cur != nullptr) {
            auto [newHead, tail] = reverse(cur, 2);
            prev->next = newHead;
            prev = tail;
            cur = tail->next;
        }
        return dummy->next;
    }
};