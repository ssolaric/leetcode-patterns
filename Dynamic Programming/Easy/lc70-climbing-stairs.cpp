class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int cur = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = cur;
            cur = cur + prev;
            prev = tmp;
        }
        return cur;
    }
};