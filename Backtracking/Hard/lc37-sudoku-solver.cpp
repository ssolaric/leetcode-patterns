class Solver {
public:
    Solver(vector<vector<char>>& board) : board(board), MAX(board.size()) {}

    bool isValidSquare(int row, int col, char c) {
        int squareStartRow = (row / 3) * 3;
        int squareStartCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[squareStartRow + i][squareStartCol + j] == c) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidRow(int row, char c) {
        for (int j = 0; j < MAX; j++) {
            if (board[row][j] == c) {
                return false;
            }
        }
        return true;
    }

    bool isValidCol(int col, char c) {
        for (int i = 0; i < MAX; i++) {
            if (board[i][col] == c) {
                return false;
            }
        }
        return true;
    }

    bool isValid(int row, int col, char c) {
        return isValidSquare(row, col, c) && isValidRow(row, c) && isValidCol(col, c);
    }

    pair<int, int> nextCell(int row, int col) {
        if (col + 1 == MAX) {
            return {row + 1, 0};
        }
        return {row, col + 1};
    }

    bool solve(int row, int col) {
        if (row == MAX && col == 0) {
            return true;
        }
        if (board[row][col] == '.') {
            for (char c = '1'; c <= '9'; c++) {
                if (isValid(row, col, c)) {
                    board[row][col] = c;
                    auto [nextRow, nextCol] = nextCell(row, col);
                    if (solve(nextRow, nextCol)) {
                        return true;
                    }
                    board[row][col] = '.';
                }
            }
            return false;
        }
        else {
            auto [nextRow, nextCol] = nextCell(row, col);
            return solve(nextRow, nextCol);
        }
    }

private:
    const int MAX;
    vector<vector<char>>& board;
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Solver solver(board);
        solver.solve(0, 0);
    }
};
