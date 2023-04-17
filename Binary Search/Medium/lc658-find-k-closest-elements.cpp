class Solution {
public:
    int findStartOfRange(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lo = 0;
        int hi = n - k;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int distStartPoint = x - arr[mid];
            int distEndPoint = arr[mid + k] - x;
            if (distStartPoint <= distEndPoint) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    // Time complexity: O(log(n - k) + k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = findStartOfRange(arr, k, x);
        return vector<int>(arr.begin() + start, arr.begin() + start + k);
    }
};
