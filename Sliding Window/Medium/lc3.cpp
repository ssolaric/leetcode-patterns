class CharCounter {
public:
    CharCounter() {
        freqs.fill(0);
    }
    
    void increment(char c) {
        if (freqs[c] == 0) {
            uniqueCount++;
        }
        freqs[c]++;
    }
    
    void decrement(char c) {
        freqs[c]--;
        if (freqs[c] == 0) {
            uniqueCount--;
        }
    }
    
    int size() {
        return uniqueCount;
    }
    
private:
    array<int, 256> freqs;
    int uniqueCount = 0;
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        CharCounter counter;
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n) {
            counter.increment(s[j]);
            while (j - i + 1 > counter.size()) {
                counter.decrement(s[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};