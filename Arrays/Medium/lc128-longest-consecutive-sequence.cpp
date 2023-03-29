class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n), sizes(n, 1), numCC(n) {
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
            sizes[roota] += sizes[rootb];
        }
        else {
            parent[roota] = rootb;
            sizes[rootb] += sizes[roota];
            if (rank[roota] == rank[rootb]) {
                rank[rootb]++;
            }
        }
        numCC--;
    }

    int ccSize(int x) {
        return sizes[Find(x)];
    }

private:
    vector<int> parent, rank, sizes;
    int numCC;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        UnionFind uf(n);
        unordered_map<int, int> indices;
        for (int i = 0; i < n; i++) {
            auto it3 = indices.find(nums[i]);
            if (it3 == indices.end()) {
                indices[nums[i]] = i;
                auto it1 = indices.find(nums[i] - 1);
                if (it1 != indices.end()) {
                    uf.Union(i, it1->second);
                }
                auto it2 = indices.find(nums[i] + 1);
                if (it2 != indices.end()) {
                    uf.Union(i, it2->second);
                }
            }
        }
        int maxCC = 0;
        for (int i = 0; i < n; i++) {
            int size = uf.ccSize(i);
            maxCC = max(maxCC, size);
        }
        return maxCC;
    }
};