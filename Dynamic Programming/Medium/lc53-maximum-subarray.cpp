class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for (auto x : nums) {
            sum = max(x, sum + x);
            ans = max(ans, sum);
        }
        return ans;
    }
};