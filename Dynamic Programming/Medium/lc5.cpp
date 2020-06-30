class Solution {
public:
    pair<int, int> expand(const string& s, int i, int j) {
        // Take into account the case where the initial substring s[i..j] is
        // not a palindrome. In this case, its length should be 0.
        int bestI = i + 1;
        int bestJ = j - 1;
        while (i >= 0 && j < s.size()) {
            if (s[i] == s[j]) {
                bestI = i;
                bestJ = j;
                i--;
                j++;
            }
            else {
                break;
            }
        }
        return {bestI, bestJ};
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int bestLen = 0;
        int bestI = 0;
        for (int i = 0; i < n; i++) {
            auto [i1, j1] = expand(s, i, i);
            auto [i2, j2] = expand(s, i, i + 1);
            int len1 = j1 - i1 + 1;
            int len2 = j2 - i2 + 1;
            if (bestLen < len1) {
                bestI = i1;
                bestLen = len1;
            }
            if (bestLen < len2) {
                bestI = i2;
                bestLen = len2;
            }
        }
        return s.substr(bestI, bestLen);
    }
};