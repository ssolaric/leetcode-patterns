class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] > arr[mid + 1]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
