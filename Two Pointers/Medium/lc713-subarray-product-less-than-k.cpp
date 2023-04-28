class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int n = nums.size();
        if (n == 1) {
            return nums[0] < k;
        }
        int prod = 1;
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n) {
            prod *= nums[j];
            while (prod >= k && prod > 1) {
                prod /= nums[i];
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};