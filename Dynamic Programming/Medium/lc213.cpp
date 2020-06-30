class Solution {
public:
    int rob1(vector<int>& nums, int start, int end) {
        int n = end - start;
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[start];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i-2] + nums[i-1 + start], dp[i-1]);
        }
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        if (n == 3) {
            return max({nums[0], nums[1], nums[2]});
        }
        nums.push_back(nums[0]);
        return max(rob1(nums, 0, n - 1), rob1(nums, 1, n));
    }
};