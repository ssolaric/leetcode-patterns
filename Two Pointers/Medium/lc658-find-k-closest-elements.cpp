class Solution {
public:
    // Time complexity: O(n)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lo = 0;
        int hi = n;

        while (hi - lo > k) {
            if (abs(arr[lo] - x) > abs(arr[hi - 1] - x)) {
                lo++;
            }
            else {
                hi--;
            }
        }
        return vector<int>(arr.begin() + lo, arr.begin() + hi);
    }
};
