class LimitedCharCounter {
public:
    LimitedCharCounter(const string& s) {
        freqs.fill(0);
        used.fill(false);
        for (char c : s) {
            used[c] = true;
            increment(c);
        }
    }
    
    void increment(char c) {
        if (!used[c]) return;
        if (freqs[c] == 0) {
            uniqueCount++;
        }
        freqs[c]++;
    }
    
    void decrement(char c) {
        if (!used[c]) return;
        freqs[c]--;
        if (freqs[c] == 0) {
            uniqueCount--;
        }
    }
    
    int size() {
        return uniqueCount;
    }
    
    bool empty() {
        return uniqueCount == 0;
    }
    
private:
    array<int, 256> freqs;
    array<bool, 256> used;
    int uniqueCount = 0;
};

class Solution {
public:
    string minWindow(string s, string t) {
        LimitedCharCounter counter(t);
        int n = s.size();
        int i = 0;
        int j = 0;
        int bestI = -1;
        int bestLen = INT_MAX;
        while (j < n) {
            counter.decrement(s[j]);
            j++;
            while (counter.empty()) {
                int len = j - i;
                if (bestLen > len) {
                    bestLen = len;
                    bestI = i;
                }
                counter.increment(s[i]);
                i++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestI, bestLen);
    }
};