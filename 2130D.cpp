#include<stack>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<string>
#include<assert.h>
#include<utility>
#include<bits/stdc++.h>
using namespace std;
#define len(x) int((x).size())
#define ll long long
#define ld long double
#define pi pair<int,int>
#define nl '\n'
#define vi vector<int>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)((x).size())
#define endl '\n'

// Debugging macros
#ifdef DEBUG
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debugv(v) cerr << #v << " = "; for(auto& x: v) cerr << x << ' '; cerr << endl
#else
#define debug(x)
#define debug2(x, y)
#define debugv(v)
#endif

// Fast IO
inline void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // For interactive problems, might want to remove these:
    // cin.exceptions(cin.failbit);
}

// Commonly used constants
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

// Shortcuts for common operations
template<typename T> inline void checkmin(T &a, T b) { if (b < a) a = b; }
template<typename T> inline void checkmax(T &a, T b) { if (b > a) a = b; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T powmod(T a, T b, T mod) { T res = 1; while (b > 0) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

// Random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int randint(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

// Solution goes here
struct BIT {
    int n;
    vector<int> bit;
    BIT(int size) : n(size), bit(size + 2, 0) {}

    void update(int x, int delta) {
        for (; x <= n + 1; x += x & -x)
            bit[x] += delta;
    }

    int query(int x) {
        int sum = 0;
        for (; x > 0; x -= x & -x)
            sum += bit[x];
        return sum;
    }

    int queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int countInversions(vector<int> &a, int maxVal) {
    BIT bit(maxVal);
    int inv = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        inv += bit.query(a[i] - 1);
        bit.update(a[i], 1);
    }
    return inv;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), a1(n), a2(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    for (int i = 0; i < n; ++i) {
        a1[i] = p[i];             // stay
        a2[i] = 2 * n - p[i];     // mirror
    }

    // Strategy 1: all stay
    int inv1 = countInversions(a1, 2 * n);
    // Strategy 2: all mirror
    int inv2 = countInversions(a2, 2 * n);

    // Strategy 3: greedy mix — choose min(p[i], 2n - p[i]) at each position
    vector<int> ag(n);
    for (int i = 0; i < n; ++i)
        ag[i] = min(p[i], 2 * n - p[i]);
    int inv3 = countInversions(ag, 2 * n);

    cout << min({inv1, inv2, inv3}) << '\n';
}

int main() {
    fastIO();
    
    // For file input/output when needed
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
        // Uncomment for interactive problems or when flushing is needed
        // cout << flush;
    }
    
    return 0;
}