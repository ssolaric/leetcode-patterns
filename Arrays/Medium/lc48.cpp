class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - i; j++) {
                // (i, j) -> (j, n - i - 1)
                // (j, n - i - 1) -> (n - i - 1, n - j - 1)
                // (n - i - 1, n - j - 1) -> (n - j - 1, i)
                // (n - j - 1, i) -> (i, j)
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }
};
