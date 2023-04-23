class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counter;
        for (char c : s) {
            counter[c]++;
        }
        auto cmp = [&counter](char c1, char c2) {
            int count1 = counter[c1];
            int count2 = counter[c2];
            if (count1 != count2) {
                return counter[c1] < counter[c2];
            }
            else {
                return c1 > c2;
            }
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
        for (auto p : counter) {
            pq.push(p.first);
        }
        string ans;
        while (!pq.empty()) {
            char top = pq.top();
            int freq = counter[top];
            for (int i = 0; i < freq; i++) {
                ans += top;
            }
            pq.pop();
        }
        return ans;
    }
};
