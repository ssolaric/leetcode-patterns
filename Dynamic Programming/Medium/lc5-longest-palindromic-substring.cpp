class Solution {
public:
    pair<int, int> expand(const string& s, int lo, int hi) {
        int n = s.size();
        while (lo >= 0 && hi < n) {
            if (s[lo] == s[hi]) {
                lo--;
                hi++;
            }
            else {
                break;
            }
        }
        return {hi - lo - 1, lo + 1};
    }

    string longestPalindrome(string s) {
        int maxLength = 0;
        int n = s.size();
        int bestStart = 0;
        for (int i = 0; i < n; i++) {
            auto [oddLength, oddStart] = expand(s, i, i);
            auto [evenLength, evenStart] = expand(s, i, i + 1);
            if (maxLength < oddLength) {
                maxLength = oddLength;
                bestStart = oddStart;
            }
            if (maxLength < evenLength) {
                maxLength = evenLength;
                bestStart = evenStart;
            }
        }
        return s.substr(bestStart, maxLength);
    }
};
