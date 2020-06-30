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
    
    int getFreq(char c) {
        return freqs[c];
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
    int characterReplacement(string s, int k) {
        CharCounter counter;
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxFreq = 0;
        int ans = 0;
        while (j < n) {
            counter.increment(s[j]);
            maxFreq = max(maxFreq, counter.getFreq(s[j]));
            // we can perform up to k operations
            // we have some most frequent character with frequency = maxFreq
            // so far we have seen j - i + 1 characters
            // we can replace up to j - i - maxFreq + 1 characters
            while (j - i - maxFreq + 1 > k) {
                counter.decrement(s[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};