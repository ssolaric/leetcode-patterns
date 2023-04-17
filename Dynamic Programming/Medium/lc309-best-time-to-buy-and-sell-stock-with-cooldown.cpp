const int INF = 1e9;

class Solution {
public:
    vector<vector<int>> memo;

    int backtrack(int depth, int n, int stocks, vector<int>& prices) {
        if (depth >= n) {
            return 0;
        }
        if (memo[depth][stocks] != -1) {
            return memo[depth][stocks];
        }
        int cooldown = backtrack(depth + 1, n, stocks, prices);
        if (stocks == 0) {
            int buy = backtrack(depth + 1, n, 1, prices) - prices[depth];
            return memo[depth][stocks] = max(buy, cooldown);
        }
        else {
            int sell = backtrack(depth + 2, n, 0, prices) + prices[depth];
            return memo[depth][stocks] = max(sell, cooldown);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.assign(n, vector<int>(2, -1));
        return backtrack(0, n, 0, prices);
    }
};
