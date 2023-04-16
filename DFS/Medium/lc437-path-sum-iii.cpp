/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

typedef long long ll;

class Solution {
public:
    int ans = 0;
    unordered_map<ll, ll> prefixSumCounter;

    void dfs(TreeNode* root, ll sum, ll targetSum) {
        if (root == nullptr) {
            return;
        }
        sum += root->val;
        ans += prefixSumCounter[sum - targetSum];
        prefixSumCounter[sum]++;

        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
        // undo counting this prefix sum, because this node will not be used anymore in other paths
        prefixSumCounter[sum]--;
    }

    // similar to https://leetcode.com/problems/subarray-sum-equals-k/
    int pathSum(TreeNode* root, int targetSum) {
        prefixSumCounter[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
    }
};
