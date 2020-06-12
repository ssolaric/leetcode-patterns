class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int lo = 0;
        int hi = n - 1;
        // [3, 4, 5, 1, 0, -1]
        //  F  F  F  T  T   T
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid < n && A[mid] > A[mid+1]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};