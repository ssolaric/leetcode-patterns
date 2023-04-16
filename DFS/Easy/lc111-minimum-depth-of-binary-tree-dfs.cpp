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
    int ans = INT_MAX;
    
    int depth(TreeNode* root, int curDepth) {
        if (root == nullptr) return 0;
        int left = depth(root->left, curDepth + 1);
        int right = depth(root->right, curDepth + 1);
        if (root->left == nullptr && root->right == nullptr) {
            ans = min(ans, 1 + curDepth);
        }
        return 1 + max(left, right);
    }
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        depth(root, 0);
        return ans;
    }
};