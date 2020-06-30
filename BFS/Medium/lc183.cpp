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
    void dfs(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {
        if (root == nullptr) return;
        if (root->left) {
            parent[root->left] = root;
        }
        if (root->right) {
            parent[root->right] = root;
        }
        dfs(root->left, parent);
        dfs(root->right, parent);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        map<TreeNode*, TreeNode*> parent;
        dfs(root, parent);
        // Traverse the tree like a graph. Launch a BFS from the target node.
        queue<TreeNode*> q;
        q.push(target);
        map<int, int> distances;
        distances[target->val] = 0;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            for (auto neighbor : {t->left, t->right, parent[t]}) {
                if (neighbor != nullptr) {
                    auto it = distances.find(neighbor->val);
                    if (it == distances.end()) {
                        distances[neighbor->val] = distances[t->val] + 1;
                        q.push(neighbor);
                    }
                    else {
                        int& distNeighbor = it->second;
                        if (distNeighbor > distances[t->val] + 1) {
                            distNeighbor = distances[t->val] + 1;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        vector<int> ans;
        for (auto [u, dist] : distances) {
            if (dist == K) {
                ans.push_back(u);
            }
        }
        return ans;
    }
};