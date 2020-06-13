class Solution {
public:
    void backtrack(int n, int k, int depth, vector<vector<int>>& ans, vector<int>& partial) {
        if (k == 0) {
            ans.push_back(partial);
            return;
        }
        for (int i = depth; i < n; i++) {
            partial.push_back(i + 1);
            backtrack(n, k - 1, i + 1, ans, partial);
            partial.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> partial;
        backtrack(n, k, 0, ans, partial);
        return ans;
    }
};