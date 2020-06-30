class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> counter(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < 1 + dp[j]) {
                        counter[i] = counter[j];
                        dp[i] = 1 + dp[j];
                    }
                    else if (dp[i] == 1 + dp[j]) {
                        counter[i] += counter[j];
                    }
                }
            }
        }
        int lis = 0;
        for (int i = 0; i < n; i++) {
            lis = max(lis, dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == lis) {
                ans += counter[i];
            }
        }
        return ans;
    }
};