class Solution {
public:
    int expand(const string& s, int i, int j) {
        int len = j - i - 1;
        int count = 0;
        while (i >= 0 && j < s.size()) {
            if (s[i] == s[j]) {
                count++;
                i--;
                j++;
            }
            else {
                break;
            }
        }
        return count;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count1 = expand(s, i, i);
            int count2 = expand(s, i, i + 1);
            ans += count1 + count2;
        }
        return ans;
    }
};