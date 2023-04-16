// Cycle detection using BFS
// https://leetcode.com/problems/course-schedule
class Solution {
public:
    bool hasCycle = false;
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> indegrees(n);
        for (auto& e : prerequisites) {
            graph[e[1]].push_back(e[0]);
            indegrees[e[0]]++;
        }
        queue<int> q;
        // The first node of a topological ordering must be a node with indegree = 0
        // This is because a course with prerequisites (indegree > 0) cannot be the first course taken.
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        
        // BFS the graph
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : graph[u]) {
                // For each neighbor node v, decrease its indegree (edge u->v)
                indegrees[v]--;
                if (indegrees[v] == 0) {
                    q.push(v);
                }
            }
            n--;
        }
        
        return n == 0;
    }
};
