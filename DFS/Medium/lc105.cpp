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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& indices,
                    int loPre, int hiPre, int loIn, int hiIn) {
        if (loPre > hiPre) return nullptr;
        int ind = indices[preorder[loPre]];
        int leftSize = ind - loIn;
        TreeNode* root = new TreeNode(preorder[loPre]);
        root->left = build(preorder, inorder, indices, loPre + 1, loPre + leftSize, loIn, ind - 1);
        root->right = build(preorder, inorder, indices, loPre + 1 + leftSize, hiPre, ind + 1, hiIn);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> indices;
        for (int i = 0; i < n; i++) {
            indices[inorder[i]] = i;
        }
        return build(preorder, inorder, indices, 0, n - 1, 0, n - 1);
    }
};