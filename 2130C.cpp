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
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) { parent.resize(n + 1); iota(parent.begin(), parent.end(), 0); }
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false; // cycle
        parent[ry] = rx;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].first >> segs[i].second;
    }

    DSU dsu(2 * n + 5);
    vector<bool> used(n, false);

    for (int i = 0; i < n; ++i) {
        int u = segs[i].first;
        int v = segs[i].second;
        if (dsu.unite(u, v)) {
            used[i] = true;
        }
    }

    vector<int> selected;
    for (int i = 0; i < n; ++i) {
        if (used[i]) selected.push_back(i + 1);
    }

    // Output
    cout << selected.size() << '\n';
    for (int idx : selected)
        cout << idx << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
