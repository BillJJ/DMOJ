#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MM = 2e5+5;

ll a[MM], dp[MM], p[MM]; // p[i]: anchor of i

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, h; cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i-1; j >= p[i-1]; j--) {
            ll v=  dp[j] + (a[j+1] - a[i])*(a[j+1] - a[i]) + h;
            if(v < dp[i]){
                dp[i] = v;
                p[i] = j;
            }
        }
    }

    cout << dp[n];
    
    return 0;
}