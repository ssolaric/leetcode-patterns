class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ind0 = 0;
        int ind1 = 0;
        int ind2 = n;
        while (ind1 < ind2) {
            if (nums[ind1] == 0) {
                swap(nums[ind0], nums[ind1]);
                ind0++;
                ind1++;
            }
            else if (nums[ind1] == 2) {
                ind2--;
                swap(nums[ind1], nums[ind2]);
            }
            else {
                ind1++;
            }
        }
    }
};