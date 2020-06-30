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
    bool validate(TreeNode* root, TreeNode* minimum, TreeNode* maximum) {
        if (root == nullptr) return true;
        if (minimum != nullptr && root->val <= minimum->val) return false;
        if (maximum != nullptr && root->val >= maximum->val) return false;
        return validate(root->left, minimum, root) && validate(root->right, root, maximum);
    }
    
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};