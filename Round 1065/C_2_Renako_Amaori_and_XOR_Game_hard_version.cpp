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
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        long long X = 0, Y = 0;
        for (int i = 0; i < n; ++i) {
            X ^= a[i];
            Y ^= b[i];
        }

        long long Z = X ^ Y;
        if (Z == 0) {
            cout << "Tie\n";
            continue;
        }

        int k = 63 - __builtin_clzll(Z);

        long long mask = 1LL << k;

        
        int lastIdx = -1;
        for (int i = n - 1; i >= 0; --i) {
            if ((a[i] ^ b[i]) & mask) {
                lastIdx = i;
                break;
            }
        }


        if ((lastIdx + 1) % 2 == 1) {
            cout << "Ajisai\n";
        } else {
            cout << "Mai\n";
        }
    }

    return 0;
}