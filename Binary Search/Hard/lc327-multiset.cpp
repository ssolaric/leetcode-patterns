class Solution {
public:
    typedef long long ll;
    // This problem is similar to LC560: https://leetcode.com/problems/subarray-sum-equals-k/
    // In that problem, we had to map prefix sums to their frequency and we searched this map
    // for an exact specific number (sum - k) = PS[j + 1] - k, where PS is the prefix sum array.
    // In this problem, we don't need to count frequencies, but we still need to search for (sum - k)
    // and count how many occurrences there are.
    // This technique is also used in LC220: https://leetcode.com/problems/contains-duplicate-iii/
    int countRangeSum(vector<int>& nums, ll lower, ll upper) {
        int n = nums.size();
        multiset<ll> sumFreqs;
        sumFreqs.insert(0);
        ll sum = 0;
        ll ans = 0;
        for (auto x : nums) {
            sum += x;
            auto it = sumFreqs.lower_bound(-upper + sum);
            if (it != sumFreqs.end()) {
                ll S_I = *it;
                if (S_I <= -lower + sum) {
                    auto it2 = sumFreqs.upper_bound(-lower + sum);
                    ans += distance(it, it2);
                }
            }
            sumFreqs.insert(sum);
        }
        return ans;
    }
};