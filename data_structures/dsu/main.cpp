#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0;i < n;i ++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu != pv) {
            if (size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
    }

    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};