#include <bits/stdc++.h>
using namespace std;

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

        // Compute prefix minima on the fly
        vector<int> pref_min(n + 1);
        pref_min[1] = pos[1];
        for (int i = 2; i <= n; ++i) {
            pref_min[i] = min(pref_min[i - 1], pos[i]);
        }

        int suff_max = pos[n];
        bool valid = true;
        for (int k = n - 1; k >= 1; --k) {
            if (pref_min[k] > suff_max) {
                valid = false;
                break;
            }
            suff_max = max(suff_max, pos[k]);
        }

        cout << (valid ? "Yes" : "No") << '\n';
    }
    return 0;
}