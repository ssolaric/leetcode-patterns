const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= m) return;
        if (grid[row][col] == '0') return;
        grid[row][col] = '0';
        for (int d = 0; d < 4; d++) {
            int nrow = row + dr[d];
            int ncol = col + dc[d];
            dfs(grid, nrow, ncol);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        int numCC = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    numCC++;
                }
            }
        }
        return numCC;
    }
};
