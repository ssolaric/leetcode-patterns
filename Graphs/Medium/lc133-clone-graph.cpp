/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*, Node*>& origToCopy) {
        Node* newNode = new Node(node->val);
        origToCopy[node] = newNode;
        for (Node* ady : node->neighbors) {
            if (origToCopy.find(ady) == origToCopy.end()) {
                Node* restOfGraph = dfs(ady, origToCopy);
                newNode->neighbors.push_back(restOfGraph);
                // This next line is not necessary:
                // origToCopy[ady] = restOfGraph;
            }
            else {
                newNode->neighbors.push_back(origToCopy[ady]);
            }
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        map<Node*, Node*> origToCopy;
        return dfs(node, origToCopy);
    }
};