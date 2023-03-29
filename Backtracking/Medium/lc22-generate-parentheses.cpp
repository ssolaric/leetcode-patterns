class Solution {
public:
    void backtrack(int numOpen, int numClose, int n, vector<string>& ans, string& partial) {
        if (numOpen == n && numClose == n) {
            ans.push_back(partial);
            return;
        }
        if (numOpen < numClose) return;
        if (numOpen == n) {
            partial += ')';
            backtrack(numOpen, numClose + 1, n, ans, partial);
            partial.pop_back();
            return;
        }

        if (numOpen == numClose) {
            partial += '(';
            backtrack(numOpen + 1, numClose, n, ans, partial);
            partial.pop_back();
        }
        else {
            partial += '(';
            backtrack(numOpen + 1, numClose, n, ans, partial);
            partial.pop_back();

            partial += ')';
            backtrack(numOpen, numClose + 1, n, ans, partial);
            partial.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string partial;
        backtrack(0, 0, n, ans, partial);
        return ans;
    }
};