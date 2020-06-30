class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool zerosFirstRow = false;
        bool zerosFirstCol = false;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // Special cases: first row and first column must me marked as zeros.
                    if (i == 0) {
                        zerosFirstRow = true;
                    }
                    if (j == 0) {
                        zerosFirstCol = true;
                    }
                    // Use the first cell of every row and column as a flag
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // Iterate the matrix, except the first row and first column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // Use the flags in the first cell of every row and column to mark all
                // the row or column with zeros.
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // Fill the first row and the first column with zeros, if they were marked before.
        if (zerosFirstRow) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (zerosFirstCol) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};