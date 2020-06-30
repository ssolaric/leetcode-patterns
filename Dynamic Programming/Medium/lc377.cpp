typedef unsigned long long ull;

class Solution {
public:
    ull combinationSum4(vector<int>& nums, ull target) {
        vector<ull> dp(target + 1);
        dp[0] = 1;
        for (int t = 1; t <= target; t++) {
            for (auto x : nums) {
                if (t - x >= 0) {
                    dp[t] += dp[t - x];
                }
            }
        }
        
        return dp[target];
    }
};