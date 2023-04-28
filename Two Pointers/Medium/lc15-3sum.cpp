class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int j = i + 1;
            int k = n - 1;
            int target = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] < target) {
                    j++;
                }
                else if (nums[j] + nums[k] > target) {
                    k--;
                }
                else {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    if (ans.empty() || ans.back() != triplet) {
                        ans.push_back(triplet);
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};