class Solution {
public:    
    bool subsetSum(int depth, int n, int target, vector<int>& nums) {
        vector<int> dp(target + 1);
        dp[0] = true;
        
        for (int i = 0; i < n; i++) {
            for (int t = target; t >= nums[i]; t--) {
                dp[t] = dp[t - nums[i]] || dp[t];
            }
        }
        return dp[target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int n = nums.size();
        int target = sum / 2;
        return subsetSum(0, n, target, nums);
    }
};
