class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // We can see this problem as an interval merging problem (https://leetcode.com/problems/merge-intervals/).
        // Each index i defines an interval [i, i + nums[i]]. If all intervals can be merged
        // into a single interval, then we can jump to the last index.
        int end = nums[0];
        for (int i = 1; i < n; i++) {
            if (i <= end) {
                // The interval [0, end] intersects the interval [i, i + nums[i]].
                // We merge these intervals.
                end = max(end, i + nums[i]);
            }
            else {
                return false;
            }
        }
        return true;
    }
};
