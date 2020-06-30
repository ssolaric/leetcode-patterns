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
class Solution {
public:
    int getMax(const vector<int>& nums, int lo, int hi) {
        int ans = nums[lo];
        for (int i = lo + 1; i <= hi; i++) {
            ans = max(ans, nums[i]);
        }
        return ans;
    }
    
    TreeNode* build(const vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return nullptr;
        auto itMax = max_element(nums.begin() + lo, nums.begin() + hi);
        TreeNode* root = new TreeNode(*itMax);
        int indMax = itMax - nums.begin();
        root->left = build(nums, lo, indMax);
        root->right = build(nums, indMax + 1, hi);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return build(nums, 0, n);
    }
};