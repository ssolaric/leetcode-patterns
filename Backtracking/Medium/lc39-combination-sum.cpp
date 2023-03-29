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
                partial.push_back(candidates[i]);
                backtrack(i, target - candidates[i], candidates, ans, partial);
                partial.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> partial;
        backtrack(0, target, candidates, ans, partial);
        return ans;
    }
};