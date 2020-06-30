class Solution {
public:
    void mergeToBack(vector<vector<int>>& ans, const vector<int>& interval) {
        if (!ans.empty() && ans.back()[1] >= interval[0]) {
            ans.back() = {ans.back()[0], max(ans.back()[1], interval[1])};
        }
        else {
            ans.push_back(interval);
        }
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            mergeToBack(ans, intervals[i]);
        }
        return ans;
    }
};