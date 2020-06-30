class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) {
            ans.push_back("");
        }
        else {
            for (int i = 0; i < n; i++) {
                vector<string> leftParts = generateParenthesis(i);
                vector<string> rightParts = generateParenthesis(n - i - 1);
                for (auto& left : leftParts) {
                    for (auto& right : rightParts) {
                        // A balanced parentheses string ALWAYS starts with "(".
                        // We use this fact to generate a new string using:
                        // 1. One part inside a pair of parentheses.
                        // 2. Another part outside of this pair of parentheses.
                        ans.push_back("(" + left + ")" + right);
                        // These options would also be fine:
                        // ans.push_back(left + "(" + right + ")");
                        // ans.push_back(right + "(" + left + ")");
                        // ans.push_back("(" + right + ")" + left); 
                    }
                }
            }
        }
        return ans;
    }
};
