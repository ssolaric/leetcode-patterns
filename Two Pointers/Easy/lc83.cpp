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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur != nullptr) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                cur = cur->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};