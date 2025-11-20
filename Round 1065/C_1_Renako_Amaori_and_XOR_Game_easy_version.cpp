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
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int A0 = 0, B0 = 0;
        for (int x : a) A0 ^= x;
        for (int x : b) B0 ^= x;

        if (A0 == B0) {
            cout << "Tie\n";
        } else {
            int lastDiff = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (a[i] != b[i]) {
                    lastDiff = i;
                    break;
                }
            }
            if ((lastDiff + 1) % 2 == 1) {  
                cout << "Ajisai\n";
            } else {
                cout << "Mai\n";
            }
        }
    }

    return 0;
}