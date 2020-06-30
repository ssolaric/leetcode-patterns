class Solution {
public:
    bool isValid(int row, int col, int n, vector<string>& partial) {
        for (int i = 0; i < partial.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (partial[i][j] == 'Q') {
                    // same column
                    if (col == j) {
                        return false;
                    }
                    // same diagonal
                    if (row - i == abs(col - j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    void backtrack(int row, int n, vector<vector<string>>& ans, vector<string>& partial) {
        if (row == n) {
            ans.push_back(partial);
            return;
        }
        string boardRow(n, '.');
        partial.push_back(boardRow);
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n, partial)) {
                partial.back()[col] = 'Q';
                backtrack(row + 1, n, ans, partial);
                partial.back()[col] = '.';    
            }
        }
        partial.pop_back();
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> partial;
        backtrack(0, n, ans, partial);
        return ans;
    }
};