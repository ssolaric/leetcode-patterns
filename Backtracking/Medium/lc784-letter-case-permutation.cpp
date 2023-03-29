class Solution {
public:
    void backtrack(int depth, const string& S, vector<string>& ans, string& partial) {
        if (depth == S.size()) {
            ans.push_back(partial);
            return;
        }
        partial.push_back(S[depth]);
        backtrack(depth + 1, S, ans, partial);
        if (isalpha(S[depth])) {
            if (islower(S[depth])) {
                partial.back() = toupper(partial.back());
            }
            else {
                partial.back() = tolower(partial.back());
            }
            backtrack(depth + 1, S, ans, partial);
        }
        partial.pop_back(); // Important! Don't forget this line.
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        string partial;
        backtrack(0, S, ans, partial);
        return ans;
    }
};