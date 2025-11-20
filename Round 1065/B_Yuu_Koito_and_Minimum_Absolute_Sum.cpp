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
        vector<long long> a(n); 
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool L_fixed = (a[0] != -1);
        bool R_fixed = (a[n-1] != -1);
        long long L_val = L_fixed ? a[0] : -1;
        long long R_val = R_fixed ? a[n-1] : -1;

        long long a0, an;
        if (L_fixed && R_fixed) {
            a0 = L_val;
            an = R_val;
        } else if (L_fixed) {
            a0 = L_val;
            an = L_val;
        } else if (R_fixed) {
            a0 = R_val;
            an = R_val;
        } else {
            a0 = 0;
            an = 0;
        }

        a[0] = a0;
        a[n-1] = an;


        for (int i = 1; i < n-1; ++i) {
            if (a[i] == -1) a[i] = 0;
        }

        long long minDiff = llabs(a[n-1] - a[0]);

        cout << minDiff << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}