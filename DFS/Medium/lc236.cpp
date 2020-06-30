/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* lcaLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* lcaRight = lowestCommonAncestor(root->right, p, q);
        if (lcaLeft != nullptr && lcaRight != nullptr) {
            return root;
        }
        else if (lcaLeft != nullptr) {
            return lcaLeft;
        }
        else if (lcaRight != nullptr) {
            return lcaRight;
        }
        else {
            return nullptr;
        }
    }
};