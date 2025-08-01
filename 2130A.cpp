#include <bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 0) ans++;
        else ans += tmp;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt = 0;
    cin >> tt;
    while(tt--){
        solve();
    }

    return 0;
}