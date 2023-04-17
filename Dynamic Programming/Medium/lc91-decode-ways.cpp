class Solution {
public:
    int countUnits(int unitsDigit) {
        return unitsDigit >= 1 && unitsDigit <= 9;
    }
    
    int countTens(int tensDigit, int unitsDigit) {
        int num = tensDigit * 10 + unitsDigit;
        return num >= 10 && num <= 26;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; i++) {
            int tensDigit = s[i - 2] - '0';
            int unitsDigit = s[i - 1] - '0';
            dp[i] = countUnits(unitsDigit) * dp[i - 1] + countTens(tensDigit, unitsDigit) * dp[i - 2];
        }
        return dp[n];
    }
};
