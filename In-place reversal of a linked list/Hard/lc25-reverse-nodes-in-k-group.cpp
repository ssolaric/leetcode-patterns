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
    
    int findLength(ListNode* head) {
        ListNode* cur = head;
        int ans = 0;
        while (cur != nullptr) {
            ans++;
            cur = cur->next;
        }
        return ans;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        int length = findLength(head);
        int count = 0;
        while (cur != nullptr) {
            if (count + k <= length) {
                auto [newHead, tail] = reverse(cur, k);
                prev->next = newHead;
                prev = tail;
                cur = tail->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
            count += k;
        }
        return dummy->next;
    }
};