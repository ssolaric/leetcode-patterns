const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    int n, m;
    bool isValid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        for (int d = 0; d < 4; d++) {
            int nrow = row + dr[d];
            int ncol = col + dc[d];
            if (isValid(nrow, ncol) && !visited[nrow][ncol]) {
                if (matrix[row][col] <= matrix[nrow][ncol]) {
                    dfs(nrow, ncol, matrix, visited);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) return {};
        m = matrix[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            atlantic[i][m-1] = true;
        }
        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            atlantic[n-1][j] = true;
        }
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dfs(i, 0, matrix, pacific);
            dfs(i, m - 1, matrix, atlantic);
        }
        
        for (int j = 0; j < m; j++) {
            dfs(0, j, matrix, pacific);
            dfs(n - 1, j, matrix, atlantic);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
