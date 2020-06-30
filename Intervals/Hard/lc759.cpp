/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    void mergeToBack(vector<Interval>& merged, Interval& toMerge) {
        if (!merged.empty() && merged.back().end > toMerge.start) {
            merged.back() = Interval{merged.back().start, max(toMerge.end, merged.back().end)};
        }
        else {
            merged.push_back(toMerge);
        }
    }
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> intervals;
        for (auto& employee : schedule) {
            for (auto& interval: employee) {
                intervals.push_back(interval);
            }
        }
        sort(intervals.begin(), intervals.end(), [](auto& i1, auto& i2) {
            if (i1.start != i2.start) {
                return i1.start < i2.start;
            }
            return i1.end < i2.end;
        });
        vector<Interval> merged;
        for (auto& i : intervals) {
            mergeToBack(merged, i);
        }
        vector<Interval> ans;
        for (int i = 1; i < merged.size(); i++) {
            if (merged[i-1].end != merged[i].start) {
                ans.push_back(Interval{merged[i-1].end, merged[i].start});
            }
        }
        
        return ans;
    }
};