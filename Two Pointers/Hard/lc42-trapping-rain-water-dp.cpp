class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     int ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         int maxLeftHeight = 0;
    //         for (int j = i - 1; j >= 0; j--) {
    //             maxLeftHeight = max(maxLeftHeight, height[j]);
    //         }
    //         int maxRightHeight = 0;
    //         for (int j = i + 1; j < n; j++) {
    //             maxRightHeight = max(maxRightHeight, height[j]);
    //         }
    //         int area = min(maxLeftHeight, maxRightHeight) - height[i];
    //         ans += max(area, 0);
    //     }
    //     return ans;
    // }
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> maxLeftHeight(n);
        maxLeftHeight[0] = height[0];
        vector<int> maxRightHeight(n);
        maxRightHeight[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            maxLeftHeight[i] = max(maxLeftHeight[i-1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            maxRightHeight[i] = max(maxRightHeight[i+1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int area = min(maxLeftHeight[i], maxRightHeight[i]) - height[i];
            ans += area;
        }
        return ans;
    }
};