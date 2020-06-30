class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // 1, 7, 11
        // 2, 4, 6
        // 1 + 2, 1 + 4, 1 + 6
        // 7 + 2, 7 + 4, 7 + 6
        // 11 + 2, 11 + 4, 11 + 6
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 == 0 || n2 == 0) {
            return {};
        }
        auto cmp = [&nums1, &nums2](pair<int, int>& p1, pair<int, int>& p2){
            int sum1 = nums1[p1.first] + nums2[p1.second];
            int sum2 = nums1[p2.first] + nums2[p2.second];
            return sum1 > sum2; // min-heap
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < n1; i++) {
            pq.push({i, 0});
        }
        vector<vector<int>> ans;
        while (!pq.empty() && k > 0) {
            auto [i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j < n2 - 1) {
                pq.push({i, j + 1});
            }
            k--;
        }
        return ans;
    }
};