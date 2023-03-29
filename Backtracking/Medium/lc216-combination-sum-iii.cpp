class Solution {
public:
    void backtrack(int depth, int k, int target, vector<vector<int>>& ans, vector<int>& partial) {
        if (k == 0) {
            if (target == 0) {
                ans.push_back(partial);
                return;
            }
            return;
        }
        for (int i = depth; i <= 9; i++) {
            if (target - i >= 0) {
                partial.push_back(i);
                backtrack(i + 1, k - 1, target - i, ans, partial);
                partial.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // We can use k numbers from 1 to 9 to add up to n
        vector<vector<int>> ans;
        vector<int> partial;
        backtrack(1, k, n, ans, partial);
        return ans;
    }
};