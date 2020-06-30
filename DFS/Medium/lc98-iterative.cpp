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
    bool isValidBST(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> s;
        int prev = 0;
        int count = 0;
        while (!s.empty() || cur != nullptr) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            count++;
            if (count > 1 && prev >= cur->val) {
                return false;
            }
            prev = cur->val;
            cur = cur->right;
        }
        return true;
    }
};