class Solution {
public:
    int bfs(vector<vector<int>>& graph, int source) {
        int n = graph.size();
        vector<int> distances(n, 1e9);
        distances[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : graph[u]) {
                if (distances[v] > distances[u] + 1) {
                    distances[v] = distances[u] + 1;
                    q.push(v);
                }
            }
        }
        int height = 0; // max distance
        for (auto dist : distances) {
            height = max(height, dist);
        }
        return height;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.size() == 0) {
            return {0};
        }
        if (edges.size() == 1) {
            return {0, 1};
        }
        vector<vector<int>> graph(n, vector<int>());
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int minHeight = 1e9;
        vector<int> heights(n);
        for (int u = 0; u < n; u++) {
            if (graph[u].size() > 1) {
                heights[u] = bfs(graph, u);
                minHeight = min(minHeight, heights[u]);    
            }
        }
        vector<int> ans;
        for (int u = 0; u < n; u++) {
            if (heights[u] == minHeight) {
                ans.push_back(u);
            }
        }
        return ans;
    }
};