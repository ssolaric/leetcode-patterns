class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        array<int, 26> counter;
        counter.fill(0);
        for (auto c : S) {
            counter[c - 'a']++;
        }
        // Find the most frequent letter.
        int mostFrequent = 0;
        for (int i = 0; i < 26; i++) {
            if (counter[mostFrequent] < counter[i]) {
                mostFrequent = i;
            }
        }
        if (counter[mostFrequent] > (n + 1) / 2) {
            return "";
        }
        string ans(n, ' ');
        int ind = 0;
        // Fill the result string using the most frequent character.
        while (counter[mostFrequent] > 0) {
            ans[ind] = mostFrequent + 'a';
            ind += 2;
            counter[mostFrequent]--;
        }
        
        // Fill the rest of the characters, in alphabetical order.
        for (int i = 0; i < 26; i++) {
            while (counter[i] > 0) {
                // If we go past the last element, restart the index at 1.
                if (ind >= n) {
                    ind = 1;
                }
                ans[ind] = i + 'a';
                ind += 2;
                counter[i]--;
            }
        }
        return ans;
    }
};