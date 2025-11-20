#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n+1), rank(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        vector<int> pos(n + 1);
        for (int i = 0; i < n; ++i) {
            pos[p[i]] = i;
        }

        // Check condition
        vector<int> pref_min(n + 1), suff_max(n + 2);
        pref_min[1] = pos[1];
        for (int i = 2; i <= n; ++i) {
            pref_min[i] = min(pref_min[i-1], pos[i]);
        }
        suff_max[n] = pos[n];
        for (int i = n-1; i >= 1; --i) {
            suff_max[i] = max(suff_max[i+1], pos[i]);
        }

        bool ok = true;
        for (int k = 1; k < n; ++k) {
            if (pref_min[k] > suff_max[k+1]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            DSU dsu(n);
            vector<pair<int, int>> edges;

            // Candidate 1: for each v, connect to largest u < v with pos[u] < pos[v]
            stack<int> st;
            for (int v = 1; v <= n; ++v) {
                while (!st.empty() && pos[st.top()] > pos[v]) {
                    st.pop();
                }
                if (!st.empty()) {
                    int u = st.top();
                    if (dsu.unite(u, v)) {
                        edges.push_back({u, v});
                    }
                }
                st.push(v);
            }

            // Candidate 2: for each v, connect to smallest w > v with pos[w] > pos[v]
            stack<int> st2;
            for (int v = n; v >= 1; --v) {
                while (!st2.empty() && pos[st2.top()] < pos[v]) {
                    st2.pop();
                }
                if (!st2.empty()) {
                    int w = st2.top();
                    if (dsu.unite(v, w)) {
                        edges.push_back({v, w});
                    }
                }
                st2.push(v);
            }

            // Output first n-1 edges
            for (int i = 0; i < n-1; ++i) {
                auto [u, v] = edges[i];
                if (u > v) swap(u, v);
                cout << u << " " << v << "\n";
            }
        }
    }
    return 0;
}