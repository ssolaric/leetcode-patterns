const int INF = 1e9;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int coin : coins) {
            for (int x = coin; x <= amount; x++) {
                dp[x] = min(dp[x], 1 + dp[x - coin]);
            }
        }
        if (dp[amount] >= INF) {
            return -1;
        }
        return dp[amount];
    }
};
