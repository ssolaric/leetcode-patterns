class Solution {
public:
    void backtrack(int depth, const vector<int>& nums, vector<vector<int>>& ans, vector<int>& partial) {
        ans.push_back(partial);
        for (int i = depth; i < nums.size(); i++) {
            if (i > depth && nums[i - 1] == nums[i]) continue;
            partial.push_back(nums[i]);
            backtrack(i + 1, nums, ans, partial);
            partial.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> partial;
        backtrack(0, nums, ans, partial);
        return ans;
    }
};