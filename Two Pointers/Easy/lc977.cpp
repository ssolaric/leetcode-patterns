class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int rightStart = 0;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (A[i] >= 0 && !found) {
                rightStart = i;
                found = true;
            }
            A[i] = A[i] * A[i];
        }
        vector<int> ans;
        int i = rightStart - 1;
        int j = rightStart;
        while (i >= 0 && j < n) {
            if (A[i] <= A[j]) {
                ans.push_back(A[i]);
                i--;
            }
            else {
                ans.push_back(A[j]);
                j++;
            }
        }
        while (i >= 0) {
            ans.push_back(A[i]);
            i--;
        }
        while (j < n) {
            ans.push_back(A[j]);
            j++;
        }
        return ans;
    }
};