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
    typedef unsigned long long ull;
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        queue<ull> ids;
        q.push(root);
        ids.push(1);
        ull ans = 0;
        while (!q.empty()) {
            int queueSize = q.size();
            ull firstId = 0;
            ull lastId = 0;
            for (int i = 0; i < queueSize; i++) {
                TreeNode* t = q.front();
                ull id = ids.front();
                if (i == 0) {
                    firstId = id;
                }
                if (i == queueSize - 1) {
                    lastId = id;
                }
                q.pop();
                ids.pop();
                if (t->left) {
                    q.push(t->left);
                    ids.push(2 * id);
                }
                if (t->right) {
                    q.push(t->right);
                    ids.push(2 * id + 1);
                }
            }
            ans = max(ans, lastId - firstId + 1);
        }
        return ans;
    }
};
