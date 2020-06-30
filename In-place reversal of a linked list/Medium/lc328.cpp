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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        
        ListNode* evenHead = head->next;
        
        int length = 0;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode* next = cur->next;
            cur->next = next->next;
            prev = cur;
            cur = next;
            length++;
        }
        length++;
        ListNode* oddTail;
        if (length % 2 == 0) {
            oddTail = prev;
        }
        else {
            oddTail = cur;
        }
        oddTail->next = evenHead;
        return dummy->next;
    }
};