class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, vector<int>& visited, vector<int>& parent) {
        visited[u] = 1;
        for (auto v : graph[u]) {
            if (visited[v] == 0) {
                parent[v] = u;
                if (dfs(graph, v, visited, parent)) {
                    return true;
                }
            }
            else if (visited[v] == 1) {
                if (parent[u] != v) {
                    return true;
                }
            }
        }
        visited[u] = 2;
        return false; // no cycle
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if (m != n - 1) return false;
        // A tree must not have cycles and must have only one connected component.
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int numCC = 0;
        vector<int> visited(n); // 0: not visited, 1: explored, 2: visited
        vector<int> parent(n, -1);
        for (int u = 0; u < n; u++) {
            if (visited[u] == 0) {
                if (dfs(graph, u, visited, parent)) {
                    return false;
                }
                numCC++;
            }
            if (numCC > 1) {
                return false;
            }
        }
        return true;
    }
};