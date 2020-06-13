const array<string, 10> digitToLetters = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

class Solution {
public:
    void backtrack(int depth, const string& digits, vector<string>& ans, string& partial) {
        if (depth == digits.size()) {
            ans.push_back(partial);
            return;
        }
        int digit = digits[depth] - '0';
        string letters = digitToLetters[digit];
        for (auto c : letters) {
            partial += c;
            backtrack(depth + 1, digits, ans, partial);
            partial.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> ans;
        string partial;
        backtrack(0, digits, ans, partial);
        return ans;
    }
};