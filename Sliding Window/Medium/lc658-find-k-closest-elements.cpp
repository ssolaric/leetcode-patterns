class Solution {
public:
    // Time complexity: O(n - k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lo = 0;
        int hi = k;
        int distancesSum = 0;
        for (int i = 0; i < k; i++) {
            distancesSum += abs(x - arr[i]);
        }
        int minDistancesSum = distancesSum;
        for (int i = k; i <= n; i++) {
            if (minDistancesSum > distancesSum) {
                minDistancesSum = distancesSum;
                lo = i - k;
                hi = i;
            }
            if (i == n) {
                break;
            }
            distancesSum += abs(arr[i] - x) - abs(arr[i - k] - x);
        }
        return vector<int>(arr.begin() + lo, arr.begin() + hi);
    }
};
