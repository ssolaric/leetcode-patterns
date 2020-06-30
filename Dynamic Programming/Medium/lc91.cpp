class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; i++) {
            int unitsDigit = s[i-1] - '0';
            int tensDigit = s[i-2] - '0';
            if (unitsDigit >= 1 && unitsDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            int total= tensDigit * 10 + unitsDigit;
            if (total >= 10 && total <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};