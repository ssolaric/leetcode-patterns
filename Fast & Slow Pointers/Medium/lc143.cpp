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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        int size = 0;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            size += 2;
        }
        // Reverse second half of the list
        ListNode* prev = nullptr;
        ListNode* cur = slow->next;
        slow->next = nullptr;
        if (fast != nullptr) {
            size++;
        }
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // Interlace both lists
        cur = head;
        ListNode* cur2 = prev;
        int secondListLength = size % 2 == 0 ? size / 2 - 1 : size / 2;
        for (int i = 0; i < secondListLength; i++) {
            ListNode* curNext = cur->next;
            ListNode* cur2Next = cur2->next;
            cur->next = cur2;
            cur2->next = curNext;
            cur = curNext;
            cur2 = cur2Next;
        }
    }
};