class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& x : nums) {
            if (x < 1 || x > n) {
                x = n + 1;
            }
        }
        // Similar idea to https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
        for (int i = 0; i < n; i++) {
            int nextInd = abs(nums[i]) - 1;
            if (nextInd < n && nums[nextInd] > 0) {
                nums[nextInd] = -nums[nextInd];
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
