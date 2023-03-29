class Solution {
public:
    void addOne(string& partial) {
        // Example: "1x1" -> ans = "1x2"
        // Example: "1x23" -> ans = "1x24"
        int n = partial.size();
        int indNotDigit = -1;
        for (int i = 0; i < n; i++) {
            if (!isdigit(partial[i])) {
                indNotDigit = i;
            }
        }

        if (indNotDigit == -1) {
            if (partial.empty()) {
                partial += "1";
            }
            else {
                partial = to_string(stoi(partial) + 1);
            }
        }
        else if (indNotDigit == n - 1) {
            partial += "1";
        }
        else {
            string prevNumberStr = partial.substr(indNotDigit + 1);
            int prevNumber = stoi(prevNumberStr);
            partial.replace(indNotDigit + 1, n - 1 - indNotDigit, to_string(prevNumber + 1));
        }
    }

    void backtrack(int depth, const string& word, vector<string>& ans, string partial) {
        if (depth == word.size()) {
            ans.push_back(partial);
            return;
        }
        partial += word[depth];
        backtrack(depth + 1, word, ans, partial);
        partial.pop_back();
        addOne(partial);
        backtrack(depth + 1, word, ans, partial);
    }

    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        string partial;
        backtrack(0, word, ans, partial);
        return ans;
    }
};