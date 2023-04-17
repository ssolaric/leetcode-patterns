class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    }
                    else if (dp[i] == 1 + dp[j]) {
                        count[i] += count[j];
                    }
                }
            }
        }
        int lis = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == lis) {
                ans += count[i];
            }
        }
        return ans;
    }
};
