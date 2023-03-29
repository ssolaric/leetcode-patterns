const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    int n, m;

    bool backtrack(vector<vector<char>>& board, int row, int col, const string& word, int wordIndex) {
        if (wordIndex == word.size()) {
            return true;
        }
        if (row < 0 || col < 0 || row >= n || col >= m) return false;
        if (board[row][col] == '-') return false;
        if (board[row][col] != word[wordIndex]) {
            return false;
        }
        char letter = board[row][col];
        board[row][col] = '-';
        for (int d = 0; d < 4; d++) {
            int nrow = row + dr[d];
            int ncol = col + dc[d];
            if (backtrack(board, nrow, ncol, word, wordIndex + 1)) {
                return true;
            }
        }
        board[row][col] = letter;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        if (n == 0) return false;
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (backtrack(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
