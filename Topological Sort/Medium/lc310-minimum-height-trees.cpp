class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> graph(n);
        for (auto& e: edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (auto leaf : leaves) {
                int ady = *graph[leaf].begin();
                graph[leaf].clear();
                graph[ady].erase(leaf);
                if (graph[ady].size() == 1) {
                    newLeaves.push_back(ady);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};