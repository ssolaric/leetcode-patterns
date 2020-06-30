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
    int findLength(ListNode* head) {
        ListNode* cur = head;
        int ans = 0;
        while (cur != nullptr) {
            ans++;
            cur = cur->next;
        }
        return ans;
    }
    
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
    
    ListNode* rotateRight(ListNode* head, int k) {
        int length = findLength(head);
        if (length <= 1) return head;
        k %= length;
        if (k == 0) return head;
        auto [newHead, tail] = reverse(head, length);
        auto [newHead2, tail2] = reverse(newHead, k);
        auto [newHead3, tail3] = reverse(tail2->next, length - k);
        tail2->next = newHead3;
        return newHead2;
    }
};