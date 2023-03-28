class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // set<int> s;
        // for (int x : nums) {
        //     if (s.find(x) != s.end()) {
        //         ans.push_back(x);
        //     }
        //     s.insert(x);
        // }
        for (int i = 0; i < n; i++) {
            int nextInd = abs(nums[i]) - 1;
            if (nums[nextInd] > 0) {
                // Found for the first time
                nums[nextInd] = -nums[nextInd];
            }
            else {
                // Found twice
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }
};
