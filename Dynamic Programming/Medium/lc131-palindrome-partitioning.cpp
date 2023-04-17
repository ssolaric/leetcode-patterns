class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void backtrack(int depth, const string& s, vector<vector<string>>& ans, vector<string>& partial) {
        if (depth == s.size()) {
            ans.push_back(partial);
            return;
        }
        for (int i = depth; i < s.size(); i++) {
            // if s[depth..i] is a palindrome, then partition the rest of the string
            if (isPalindrome(s, depth, i)) {
                partial.push_back(s.substr(depth, i - depth + 1));
                backtrack(i + 1, s, ans, partial);
                partial.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partial;
        backtrack(0, s, ans, partial);
        return ans;
    }
};