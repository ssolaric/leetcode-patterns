class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int prev = 0;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = cur;
            cur = max(cur, prev + nums[i-1]);
            prev = tmp;
        }
        return cur;
    }
};