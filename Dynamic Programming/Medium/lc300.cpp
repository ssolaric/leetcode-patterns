class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            int maxDP = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxDP = max(maxDP, dp[j]);
                }
            }
            dp[i] = 1 + maxDP;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};