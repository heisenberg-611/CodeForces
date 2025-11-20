#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000003;
const int MAXF = MOD;
vector<long long> fact(MAXF), inv_fact(MAXF);

long long modpow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAXF; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv_fact[MAXF-1] = modpow(fact[MAXF-1], MOD-2, MOD);
    for (int i = MAXF-2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        long long best_ops = LLONG_MAX;
        long long total_ways = 0;

        for (int d = 0; d <= 60; d++) {
            long long pow2 = (d == 0 ? 1LL : (1LL << d));


            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (pow2 > b[i] || a[i] > b[i] / pow2) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                break;
            }

            vector<long long> high(n);
            long long H = 0;
            long long inc_sum = 0;
            vector<int> bit_count(d, 0); 

            for (int i = 0; i < n; i++) {
                long long r = b[i] - a[i] * pow2;
                high[i] = r >> d;
                long long low = r & (pow2 - 1);
                int pc = __builtin_popcountll(low);
                inc_sum += high[i] + pc;
                H += high[i];

                for (int p = 0; p < d; p++) {
                    if (low & (1LL << p)) {
                        bit_count[p]++;
                    }
                }
            }

            long long ops = d + inc_sum;
            if (ops < best_ops) {
                best_ops = ops;
                total_ways = 0;
            }
            if (ops == best_ops) {
                long long ways = 1;

               
                if (H >= MOD) {
                    ways = 0;
                } else {
                    ways = fact[H];
                    for (int i = 0; i < n; i++) {
                        ways = ways * inv_fact[high[i]] % MOD;
                    }
                }

              
                if (ways != 0) {
                    for (int p = 0; p < d; p++) {
                        ways = ways * fact[bit_count[p]] % MOD;
                    }
                }

                total_ways = (total_ways + ways) % MOD;
            }
        }

        cout << best_ops << " " << total_ways << "\n";
    }

    return 0;
}