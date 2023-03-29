class Solution {
public:
    void backtrack(int depth, int target, const vector<int>& candidates, vector<vector<int>>& ans,
                   vector<int>& partial) {
        if (target == 0) {
            ans.push_back(partial);
            return;
        }
        for (int i = depth; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                if (i > depth && candidates[i - 1] == candidates[i]) continue;
                partial.push_back(candidates[i]);
                backtrack(i + 1, target - candidates[i], candidates, ans, partial);
                partial.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> partial;
        backtrack(0, target, candidates, ans, partial);
        return ans;
    }
};