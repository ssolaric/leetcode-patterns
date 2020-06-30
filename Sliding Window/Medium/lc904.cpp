class IntCounter {
public:
    IntCounter() {
        freqs.fill(0);
    }
    
    void increment(int x) {
        if (freqs[x] == 0) {
            uniqueCount++;
        }
        freqs[x]++;
    }
    
    void decrement(int x) {
        freqs[x]--;
        if (freqs[x] == 0) {
            uniqueCount--;
        }
    }
    
    int size() {
        return uniqueCount;
    }
    
private:
    array<int, 40005> freqs;
    int uniqueCount = 0;
};

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        IntCounter counter;
        int i = 0;
        int j = 0;
        int n = tree.size();
        int ans = 0;
        while (j < n) {
            counter.increment(tree[j]);
            while (counter.size() > 2) {
                counter.decrement(tree[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};