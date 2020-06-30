class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (dp[i]) {
                for (int j = i + 1; j <= n; j++) {
                    dp[j] = dp[j] || (wordSet.find(s.substr(i, j - i)) != wordSet.end());
                }
            }
        }
        return dp[n];
    }
};