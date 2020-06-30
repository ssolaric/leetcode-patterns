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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool toReverse = false;
        while (!q.empty()) {
            int queueSize = q.size();
            vector<int> partial;
            for (int i = 0; i < queueSize; i++) {
                TreeNode* t = q.front();
                q.pop();
                partial.push_back(t->val);
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
            if (toReverse) {
                reverse(partial.begin(), partial.end());
            }
            ans.push_back(partial);
            toReverse = !toReverse;
        }
        return ans;
    }
};