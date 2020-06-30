class UnionFind {
public:
    UnionFind(int n): parent(n), rank(n), numCC(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int Find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }
    
    void Union(int a, int b) {
        int roota = Find(a);
        int rootb = Find(b);
        if (roota == rootb) return;
        if (rank[roota] > rank[rootb]) {
            parent[rootb] = roota;
        }
        else {
            parent[roota] = rootb;
            if (rank[roota] == rank[rootb]) {
                rank[rootb]++;
            }
        }
        numCC--;
    }
    
    int size() {
        return numCC;
    }
    
private:
    vector<int> parent, rank;
    int numCC;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto& e : edges) {
            uf.Union(e[0], e[1]);
        }
        return uf.size();
    }
};