class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, vector<int>& visited) {
        visited[u] = 1;
        for (auto v : graph[u]) {
            if (visited[v] == 0) {
                if (dfs(graph, v, visited)) {
                    return true;
                }
            }
            else if (visited[v] == 1) {
                return true;
            }
        }
        visited[u] = 2;
        return false; // no cycle
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& e : prerequisites) {
            graph[e[1]].push_back(e[0]);
        }
        vector<int> visited(numCourses, 0); // 0: not visited, 1: explored, 2: visited
        for (int u = 0; u < numCourses; u++) {
            if (visited[u] == 0) {
                if (dfs(graph, u, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
};