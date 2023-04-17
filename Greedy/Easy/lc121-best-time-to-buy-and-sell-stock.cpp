class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minimum = INT_MAX;
        int curMax = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            curMax = max(curMax, prices[i]);
            if (minimum > prices[i]) {
                minimum = prices[i];
                curMax = minimum;
            }
            int profit = curMax - minimum;
            ans = max(ans, profit);
        }
        return ans;
    }
};