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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = lists[0];
        auto cmp = [](ListNode* l1, ListNode* l2) {
            return l1->val > l2->val; // min-heap
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }
        
        int n = lists.size();
        ListNode* cur = dummy;
        while (!pq.empty()) {
            ListNode* l = pq.top();
            pq.pop();
            ListNode* next = l->next;
            cur->next = l;
            if (next) {
                pq.push(next);
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};