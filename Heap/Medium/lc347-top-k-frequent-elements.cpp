class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        for (auto x : nums) {
            counter[x]++;
        }
        auto cmp = [&counter](int x, int y) {
            return counter[x] > counter[y]; // min-heap
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto [x, countX] : counter) {
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};