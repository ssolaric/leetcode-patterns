class Solution {
public:
    string frequencySort(string s) {
        array<int, 256> counter;
        counter.fill(0);
        for (auto x : s) {
            counter[x]++;
        }
        int maxCount = *max_element(counter.begin(), counter.end());
        
        vector<vector<char>> buckets(maxCount + 1);
        for (int c = 0; c < 256; c++) {
            if (counter[c] > 0) {
                buckets[counter[c]].push_back(c);
            }
        }
        
        
        string ans;
        for (int freq = maxCount; freq >= 1; freq--) {
            for (char c : buckets[freq]) {
                ans += string(freq, c);
            }
        }
        return ans;
    }
};