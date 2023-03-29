class Solution {
public:
    void backtrack(int depth, const vector<int>& nums, vector<bool>& visited, vector<vector<int>>& ans,
                   vector<int>& partial) {
        if (depth == nums.size()) {
            ans.push_back(partial);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                partial.push_back(nums[i]);
                backtrack(depth + 1, nums, visited, ans, partial);
                partial.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> partial;
        int n = nums.size();
        vector<bool> visited(n, false);
        backtrack(0, nums, visited, ans, partial);
        return ans;
    }
};