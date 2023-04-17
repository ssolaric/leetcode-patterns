class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, 1);
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[j] < nums[i]) {
    //                 dp[i] = max(dp[i], 1 + dp[j]);
    //             }
    //         }
    //     }
    //     return *max_element(dp.begin(), dp.end());
    // }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> piles;
        for (int x : nums) {
            auto it = lower_bound(piles.begin(), piles.end(), x);
            if (it == piles.end()) {
                piles.push_back(x);
            }
            else {
                *it = x;
            }
        }
        return piles.size();
    }
};
