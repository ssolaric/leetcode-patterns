class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi) {
        int posPivot = (lo + hi) / 2;
        int pivot = nums[posPivot];
        swap(nums[posPivot], nums[hi]);
        int i = lo;
        for (int j = lo; j < hi; j++) {
            if (nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[hi]);
        return i;
    }
    
    void quickselect(vector<int>& nums, int lo, int hi, int k) {
        if (lo >= hi) {
            return;
        }
        int p = partition(nums, lo, hi);
        if (p < k) {
            quickselect(nums, p + 1, hi, k);
        }
        else if (p > k) {
            quickselect(nums, lo, p - 1, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k--;
        int n = nums.size();
        quickselect(nums, 0, n - 1, k);
        return nums[k];
    }
};
