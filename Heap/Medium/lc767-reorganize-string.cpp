class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        map<char, int> counter;
        for (auto c : S) {
            counter[c]++;
        }
        auto cmp = [](pair<int, char>& c1, pair<int, char>& c2) {
            if (c1.first != c2.first) {
                return c1.first < c2.first;
            }
            return c1.second > c2.second;
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> pq(cmp);
        for (auto [c, freq] : counter) {
            pq.push({freq, c});
        }

        string ans;
        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top();
            pq.pop();
            auto [f2, c2] = pq.top();
            pq.pop();
            ans += c1;
            ans += c2;
            if (--f1 > 0) {
                pq.push({f1, c1});
            }
            if (--f2 > 0) {
                pq.push({f2, c2});
            }
        }
        if (pq.size() > 0) {
            ans += pq.top().second;
        }
        if (ans.size() < n) {
            return "";
        }
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i-1] == ans[i]) {
                return "";
            }
        }
        return ans;
    }
};