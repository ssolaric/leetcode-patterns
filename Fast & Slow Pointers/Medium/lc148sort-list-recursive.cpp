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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = l1;
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 == nullptr) {
            cur->next = l2;
        }
        if (l2 == nullptr) {
            cur->next = l1;
        }
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left, right);
    }
};