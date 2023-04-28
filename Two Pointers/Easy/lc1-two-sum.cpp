class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> toIndex;
        for (int i = 0; i < nums.size(); i++) {
            auto it = toIndex.find(target - nums[i]);
            if (it != toIndex.end()) {
                return {it->second, i};
            }
            toIndex[nums[i]] = i;
        }
        return {};
    }
};