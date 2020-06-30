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
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prevTail) {
        // ListNode* dummy = new ListNode(-1);
        // dummy->next = l1;
        // Instead of using a dummy head, use prevTail as the dummy node.
        ListNode* cur = prevTail;
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
        // return dummy->next;
        // Instead of returning the head of the merged list, return its tail
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        return cur;
    }
    
    int length(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }
        return count;
    }
    
    ListNode* split(ListNode* head, int n) {
        ListNode* cur = head;
        for (int i = 0; i < n - 1 && cur != nullptr; i++) {
            cur = cur->next;
        }
        if (cur == nullptr) return nullptr;
        ListNode* secondList = cur->next;
        cur->next = nullptr;
        return secondList;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(-1, head);
        int size = length(head);
        for (int blockSize = 1; blockSize < size; blockSize *= 2) {
            // We need to merge pairs of consecutive blocks:
            // These ranges are [i, i + blockSize[ and [i + blockSize, i + 2 * blockSize[
            ListNode* cur = dummy->next; // head
            // Use a tail node in order to connect the last node of each merged list
            // with the first node of the next one.
            ListNode* tail = dummy;
            while (cur != nullptr) {
                ListNode* firstBlock = cur;
                ListNode* secondBlock = split(firstBlock, blockSize);
                cur = split(secondBlock, blockSize);
                tail = merge(firstBlock, secondBlock, tail);
            }
        }
        return dummy->next;
    }
};
