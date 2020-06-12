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
    bool equal(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) {
            return true;
        }
        else if (s == nullptr) {
            return false;
        }
        else if (t == nullptr) {
            return false;
        }
        else {
            return s->val == t->val && equal(s->left, t->left) && equal(s->right, t->right);
        }
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) {
            return true;
        }
        else if (s == nullptr) {
            return false;
        }
        else if (t == nullptr) {
            return true;
        }
        else {
            return isSubtree(s->left, t) || isSubtree(s->right, t) || equal(s, t);
        }
    }
};