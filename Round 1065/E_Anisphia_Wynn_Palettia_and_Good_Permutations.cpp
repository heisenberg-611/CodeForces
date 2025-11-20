#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> res;
        res.reserve(n);

        // 1. All even numbers
        for (int i = 2; i <= n; i += 2) {
            res.push_back(i);
        }
        // 2. All odd multiples of 3 (i % 6 == 3)
        for (int i = 3; i <= n; i += 6) {
            res.push_back(i);
        }
        // 3. All other odds except 1
        for (int i = 5; i <= n; i += 2) {
            if (i % 3 != 0) {
                res.push_back(i);
            }
        }
        // 4. Append 1 at the end
        res.push_back(1);

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}