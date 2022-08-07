#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=3e4+5;

int a[MM], dp[MM][505], n, k, w;

int f(int i, int m){
    if(i >= n+1 || m == 0) return 0;
    if(dp[i][m]) return dp[i][m];

    dp[i][m] = max(a[i] + f(i+w, m-1), f(i+1, m));
    return dp[i][m];
}

void solve(){
    cin >> n >> k >> w;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < w && j <= n;j++){
            a[i] += a[i+j];
        }
    }
    cout << f(1, k) << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}