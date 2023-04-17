class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int tmpMaxProd = maxProd;
            int tmpMinProd = minProd;
            maxProd = max({nums[i] * tmpMaxProd, nums[i] * tmpMinProd, nums[i]});
            minProd = min({nums[i] * tmpMaxProd, nums[i] * tmpMinProd, nums[i]});
            ans = max(ans, maxProd);
        }
        return ans;
    }
};