class Solution {
public:
    void mergeToBack(vector<vector<int>>& intervals, vector<int>& toMerge) {
        if (!intervals.empty() && intervals.back()[1] >= toMerge[0]) {
            intervals.back() = {intervals.back()[0], max(intervals.back()[1], toMerge[1])};
        }
        else {
            intervals.push_back(toMerge);
        }
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return {newInterval};
        vector<vector<int>> ans;
        bool newMerged = false;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] < newInterval[0]) {
                mergeToBack(ans, intervals[i]);
            }
            else {
                if (!newMerged) {
                    mergeToBack(ans, newInterval);
                    newMerged = true;    
                }
                mergeToBack(ans, intervals[i]);
            }
        }
        if (!newMerged) {
            mergeToBack(ans, newInterval);
            newMerged = true;    
        }
        return ans;
    }
};