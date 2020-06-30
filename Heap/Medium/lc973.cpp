class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [&points](vector<int>& p1, vector<int>& p2) {
            int dist1 = p1[0] * p1[0] + p1[1] * p1[1];
            int dist2 = p2[0] * p2[0] + p2[1] * p2[1];
            return dist1 < dist2; // max-heap
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto& p : points) {
            pq.push(p);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};