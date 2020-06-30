class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        int m = matrix[0].size();
        vector<int> ans;
        int leftCol = 0;
        int rightCol = m - 1;
        int topRow = 0;
        int bottomRow = n - 1;
        int dir = 0;
        int i = 0;
        int j = 0;
        while (ans.size() < n * m) {
            ans.push_back(matrix[i][j]);
            if (dir == 0) {
                if (j == rightCol) {
                    dir++;
                    topRow++;
                    i++;
                }
                else {
                    j++;
                }
            }
            else if (dir == 1) {
                if (i == bottomRow) {
                    dir++;
                    rightCol--;
                    j--;
                }
                else {
                    i++;
                }
            }
            else if (dir == 2) {
                if (j == leftCol) {
                    dir++;
                    bottomRow--;
                    i--;
                }
                else {
                    j--;
                }
            }
            else {
                if (i == topRow) {
                    dir = 0;
                    leftCol++;
                    j++;
                }
                else {
                    i--;
                }
            }
        }
        return ans;
    }
};