class Solution {
public:
    bool connect(const string& word1, const string& word2, vector<vector<int>>& graph, set<char>& visited) {
        // In the alien language: word1 < word2 lexicographically
        int n1 = word1.size();
        int n2 = word2.size();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            if (word1[i] == word2[j]) {
                auto it = visited.find(word1[i]);
                if (it == visited.end()) {
                    visited.insert(word1[i]);
                }
                i++; j++; continue;
            }
            
            auto it1 = visited.find(word1[i]);
            auto it2 = visited.find(word2[j]);
            
            if (it1 == visited.end() && it2 == visited.end()) {
                graph[word1[i] - 'a'].push_back(word2[j]);
                visited.insert(word1[i]);
                visited.insert(word2[j]);
                return true;
            }
            else if (it1 == visited.end()) {
                graph[word1[i] - 'a'].push_back(word2[j]);
                visited.insert(word1[i]);
                return true;
            }
            else if (it2 == visited.end()) {
                graph[word1[i] - 'a'].push_back(word2[j]);
                visited.insert(word2[j]);
                return true;
            }
            else {
                // A cycle might be formed here. Since by this point we don't know the relative order
                // between word1[i] and word2[j], just go ahead and create a connection.
                // We can detect this cycle later.
                graph[word1[i] - 'a'].push_back(word2[j]);
                return true;
            }
        }
        return i == n1;
    }
    
    string ans;
    bool hasCycle = false;
    
    void dfs(int u, vector<vector<int>>& graph, vector<int>& traversed) {
        traversed[u] = 1;
        for (auto v : graph[u]) {
            if (traversed[v - 'a'] == 0) {
                dfs(v - 'a', graph, traversed);
            }
            else if (traversed[v - 'a'] == 1) {
                hasCycle = true;
                return;
            }
        }
        ans += char(u + 'a');
        traversed[u] = 2;
    }
    
    string alienOrder(vector<string>& words) {
        vector<vector<int>> graph(26);
        set<char> visited;
        
        vector<bool> requiredLetters(26);
        for (auto& s : words) {
            for (auto& c : s) {
                requiredLetters[c - 'a'] = true;
            }
        }
        
        int numWords = words.size();
        int order = 0;
        for (int i = 1; i < numWords; i++) {
            if (!connect(words[i-1], words[i], graph, visited)) {
                return "";
            }
        }
        vector<int> traversed(26); // 0: not visited, 1: explored, 2: visited
        for (int i = 0; i < 26; i++) {
            if (requiredLetters[i] && traversed[i] == 0) {
                dfs(i, graph, traversed);
            }
        }
        if (hasCycle) {
            return "";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};