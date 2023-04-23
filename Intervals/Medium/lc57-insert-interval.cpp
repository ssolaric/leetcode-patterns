class Solution {
public:
    void mergeToBack(vector<vector<int>>& ans, vector<int>& i) {
        if (ans.empty() || ans.back()[1] < i[0]) {
            ans.push_back(i);
        }
        else {
            ans.back() = {ans.back()[0], max(ans.back()[1], i[1])};
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        bool merged = false;
        for (auto& i : intervals) {
            if (i[0] <= newInterval[0]) {
                mergeToBack(ans, i);
            }
            else if (!merged) {
                mergeToBack(ans, newInterval);
                mergeToBack(ans, i);
                merged = true;
            }
            else {
                mergeToBack(ans, i);
            }
        }
        if (!merged) {
            mergeToBack(ans, newInterval);
        }
        return ans;
    }
};
