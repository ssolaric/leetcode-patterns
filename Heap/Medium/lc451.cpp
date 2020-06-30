class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> counter(256);
        for (auto x : s) {
            counter[x] = {counter[x].first + 1, x};
        }
        auto cmp = [](pair<int, char>& x, pair<int, char>& y) {
            int cntX = x.first;
            int cntY = y.first;
            if (cntX != cntY) {
                return cntX > cntY;
            }
            return x < y;
        };
        sort(counter.begin(), counter.end(), cmp);
        string ans;
        for (auto p : counter) {
            ans += string(p.first, p.second);
        }
        return ans;
    }
};