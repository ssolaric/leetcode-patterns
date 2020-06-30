class Solution {
public:
    int f(int n, int m, vector<vector<int>>& memo) {
        if (n == 1 || m == 1) {
            return 1;
        }
        if (memo[n][m] != -1) {
            return memo[n][m];
        }
        memo[n][m] = f(n - 1, m, memo) + f(n, m - 1, memo);
        return memo[n][m];
    }
    
    int uniquePaths(int m, int n) {
        if (n == 0 || m == 0) return 0;
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return f(n, m, memo);
    }
};