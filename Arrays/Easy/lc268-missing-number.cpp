class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int realSum = accumulate(nums.begin(), nums.end(), 0);
        return expectedSum - realSum;
    }
};
