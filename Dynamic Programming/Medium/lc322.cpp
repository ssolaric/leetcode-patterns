class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for (int total = 1; total <= amount; total++) {
            for (auto c : coins) {
                if (total - c >= 0) {
                    dp[total] = min(dp[total], dp[total - c] + 1);
                }
            }
        }
        if (dp[amount] >= 1e9) {
            return -1;
        }
        return dp[amount];
    }
};