class LimitedCharCounter {
public:
    LimitedCharCounter(const string& s) {
        freqs.fill(0);
        used.fill(false);
        for (auto c : s) {
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
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false;
        LimitedCharCounter counter(s1);
        
        for (int i = 0; i < n1; i++) {
            counter.decrement(s2[i]);
        }
        if (counter.empty()) {
            return true;
        }
        
        for (int i = n1; i < n2; i++) {
            counter.decrement(s2[i]);
            counter.increment(s2[i - n1]);
            if (counter.empty()) {
                return true;
            }
        }
        return false;
    }
};