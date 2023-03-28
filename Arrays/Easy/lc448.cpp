class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // set<int> s;
        // for (int x : nums) {
        //     s.insert(x);
        // }
        for (int i = 0; i < n; i++) {
            int nextInd = abs(nums[i]) - 1;
            if (nums[nextInd] > 0) {
                nums[nextInd] = -nums[nextInd];
            }
        }
        // for (int num = 1; num <= n; num++) {
        //     if (s.find(num) == s.end()) {
        //         ans.push_back(num);
        //     }
        // }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
