/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        int numLevels = maxDepth(root);
        int level = 0;
        ans += to_string(root->val);
        while (!q.empty()) {
            level++;
            int queueSize = q.size();
            // This covers an entire level of the tree
            for (int i = 0; i < queueSize; i++) {
                TreeNode* front = q.front();
                q.pop();
                // This covers the children of a node
                bool leftNull = front->left == nullptr;
                bool rightNull = front->right == nullptr;
                if (leftNull && rightNull) {
                    // do nothing
                    if (level < numLevels) {
                        ans += " null null";
                    }
                }
                else if (leftNull) {
                    q.push(front->right);
                    if (level < numLevels) {
                        ans += " null";
                    }
                    ans += " " + to_string(front->right->val);
                }
                else if (rightNull) {
                    q.push(front->left);
                    ans += " " + to_string(front->left->val);
                    if (level < numLevels) {
                        ans += " null";
                    }
                }
                else {
                    q.push(front->left);
                    ans += " " + to_string(front->left->val);
                    q.push(front->right);
                    ans += " " + to_string(front->right->val);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream iss(data);
        string aux;
        iss >> aux;
        TreeNode* root = new TreeNode(stoi(aux));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            // This covers the children of a node
            string left, right;
            if (iss >> left) {
                if (left != "null") {
                    front->left = new TreeNode(stoi(left));
                    q.push(front->left);
                }
            }
            else {
                break;
            }
            if (iss >> right) {
                if (right != "null") {
                    front->right = new TreeNode(stoi(right));
                    q.push(front->right);
                }
            }
            else {
                break;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
