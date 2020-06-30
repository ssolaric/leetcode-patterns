class Solution {
public:
    int subsetSum(int depth, int n, int sum, vector<int>& nums, vector<vector<int>>& memo) {
        if (sum < 0) {
            return 0;
        }
        if (depth == n) {
            return sum == 0;
        }
        if (memo[depth][sum] != -1) {
            return memo[depth][sum];
        }
        memo[depth][sum] = subsetSum(depth + 1, n, sum - nums[depth], nums, memo) || subsetSum(depth + 1, n, sum, nums, memo);
        return memo[depth][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (auto x : nums) {
            totalSum += x;
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(totalSum + 1, -1));
        return subsetSum(0, n, totalSum / 2, nums, memo) == 1;
    }
};