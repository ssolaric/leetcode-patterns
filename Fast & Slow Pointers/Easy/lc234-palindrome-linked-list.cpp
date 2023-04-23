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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            count += 2;
        }
        if (fast != nullptr && fast->next == nullptr) {
            count++;
        }
        // Reverse list until slow
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != slow) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* firstHalf = prev;
        ListNode* secondHalf = count % 2 == 0 ? slow : slow->next;
        ListNode* cur1 = firstHalf;
        ListNode* cur2 = secondHalf;
        
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val == cur2->val) {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
