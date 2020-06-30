class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        auto cmp = [&matrix](pair<int, int>& p1, pair<int, int>& p2) {
            return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            pq.push({i, 0});
        }
        
        for (int i = 0; i < k - 1; i++) {
            auto [row, col] = pq.top();
            int num = matrix[row][col];
            pq.pop();
            if (col < m - 1) {
                pq.push({row, col + 1});
            }
        }
        auto [row, col] = pq.top();
        return matrix[row][col];
    }
};