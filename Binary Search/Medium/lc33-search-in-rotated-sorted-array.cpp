class Solution {
public:
    int findMinIndex(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= nums[n-1]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    int search(vector<int>& nums, int target, int lo, int hi) {
        int n = nums.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int minIndex = findMinIndex(nums);
        int n = nums.size();
        int ind1 = search(nums, target, 0, minIndex - 1);
        if (ind1 != -1) {
            return ind1;
        }
        int ind2 = search(nums, target, minIndex, n - 1);
        return ind2;
    }
};
