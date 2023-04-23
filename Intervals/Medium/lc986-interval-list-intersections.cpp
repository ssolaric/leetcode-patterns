class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int na = A.size();
        int nb = B.size();
        if (na == 0 || nb == 0) return {};
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        while (i < na && j < nb) {
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            if (start <= end) {
                ans.push_back({start, end});
            }
            if (A[i][1] <= B[j][1]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};
