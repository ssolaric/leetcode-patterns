class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int minDif = 1e9;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            int newTarget = target - nums[i];
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int dif = abs(sum - target);
                if (dif < minDif) {
                    minDif = dif;
                    ans = sum;
                }
                if (nums[j] + nums[k] < newTarget) {
                    j++;
                }
                else if (nums[j] + nums[k] > newTarget){
                    k--;
                }
                else {
                    return target;
                }
            }
        }
        return ans;
    }
};