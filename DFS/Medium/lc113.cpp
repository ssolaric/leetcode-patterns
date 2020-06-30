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
    void dfs(TreeNode* root, int sum, vector<vector<int>>& ans, vector<int>& partial) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) {
                partial.push_back(root->val);
                ans.push_back(partial);
                partial.pop_back();
                return;
            }
        }
        partial.push_back(root->val);
        dfs(root->left, sum - root->val, ans, partial);
        partial.pop_back();
        partial.push_back(root->val);
        dfs(root->right, sum - root->val, ans, partial);
        partial.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> partial;
        dfs(root, sum, ans, partial);
        return ans;
    }
};