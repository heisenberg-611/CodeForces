#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        long long a_prev = 0; // a_1 can be 1, but for a_2 we need > a_prev
        long long ans = 0;

        // positions i = 2 to n
        for (int i = 2; i <= n; i++) {
            // need to leave (n - i) numbers after this, so a_i <= m - (n - i)
            long long R = m - (n - i);
            if (R <= a_prev) {
                // no room, should not happen if n <= m
                // but just in case, break
                break;
            }

            // find max k such that i^k <= R
            long long p = 1; // will become i^max_k
            int max_k = 0;
            // while i^(max_k+1) <= R
            while (p <= R / i) { // ensures p*i <= R, no overflow
                p *= i;
                max_k++;
            }
            // now p = i^max_k, and i^(max_k+1) > R

            int best_k = 0;
            long long best_x = a_prev + 1; // default: take next integer, v=0

            // try k from max_k down to 1
            long long cur_p = p;
            for (int k = max_k; k >= 1; k--) {
                // smallest multiple of cur_p > a_prev
                long long q = a_prev / cur_p;
                long long x = cur_p * (q + 1);
                if (x <= R) {
                    best_k = k;
                    best_x = x;
                    break;
                }
                // prepare next lower power: cur_p /= i
                if (cur_p % i != 0) break; // shouldn't happen for k>=1
                cur_p /= i;
            }

            ans += best_k;
            a_prev = best_x;
        }

        cout << ans << '\n';
    }

    return 0;
}