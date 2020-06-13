class Solution {
public:
    void backtrack(int depth, const vector<int>& nums, vector<vector<int>>& ans, vector<int>& partial) {
        ans.push_back(partial);
        for (int i = depth; i < nums.size(); i++) {
            partial.push_back(nums[i]);
            backtrack(i + 1, nums, ans, partial);
            partial.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> partial;
        backtrack(0, nums, ans, partial);
        return ans;
    }
};