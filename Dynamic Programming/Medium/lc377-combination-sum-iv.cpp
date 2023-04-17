class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;
        for (int t = 1; t <= target; t++) {
            for (auto x : nums) {
                if (x <= t) {
                    dp[t] += dp[t - x];
                }
            }
        }
        return dp[target];
    }
};
