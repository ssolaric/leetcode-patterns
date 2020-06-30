class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        // set<int> s;
        // for (auto x : nums) {
        //     if (s.find(x) != s.end()) {
        //         ans.push_back(x);
        //     }
        //     s.insert(x);
        // }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int nextInd = abs(nums[i]) - 1;
            if (nums[nextInd] > 0) {
                
            }
            else {
                ans.push_back(abs(nums[i]));
            }
            nums[nextInd] = -nums[nextInd];
        }
        return ans;
    }
};