class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] <= nums[n - 1]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return nums[lo];
    }
};
