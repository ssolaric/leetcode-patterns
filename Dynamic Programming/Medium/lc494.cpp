typedef long long ll;
class Solution {
public:
    ll f(ll depth, ll n, ll target, vector<int>& nums, map<pair<ll, ll>, ll>& memo) {
        if (depth == n) {
            return target == 0;
        }
        auto it = memo.find({depth, target});
        if (it != memo.end()) {
            return it->second;
        }
        ll ans = f(depth + 1, n, target - nums[depth], nums, memo) +
            f(depth + 1, n, target + nums[depth], nums, memo);
        memo[{depth, target}] = ans;
        return ans;
    }
    
    ll findTargetSumWays(vector<int>& nums, ll S) {
        ll n = nums.size();
        map<pair<ll, ll>, ll> memo;
        return f(0, n, S, nums, memo);
    }
};