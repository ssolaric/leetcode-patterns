class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        deque<pair<int, int>> dq; // index, value
        vector<int> ans;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            // First dequeue if necessary
            // The current window is the interval [i - k, i - 1]
            // The next window is the interval [i - k + 1, i]
            // We need to remove from the deque those elements with index less than i - k + 1
            while (!dq.empty() && dq.front().first <= i - k) {
                dq.pop_front();
            }
            
            // Then remove from deque the items that are less than the incoming value
            while (!dq.empty() && A[i] > dq.back().second) {
                dq.pop_back();
            }
            
            // Enqueue
            dq.push_back({i, A[i]});
            if (i >= k - 1) {
                ans.push_back(dq.front().second);
            }
        }
        return ans;
    }
};