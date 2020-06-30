class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        bool obstacle = false;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 1) {
                obstacle = true;
            }
            dp[i][0] = obstacle ? 0 : 1;
        }
        obstacle = false;
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[0][j] == 1) {
                obstacle = true;
            }
            dp[0][j] = obstacle ? 0 : 1;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i-1][j] == 0) {
                    dp[i][j] += dp[i-1][j];
                }
                
                if (obstacleGrid[i][j-1] == 0) {
                    dp[i][j] += dp[i][j-1];
                }
                
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n-1][m-1];
    }
};