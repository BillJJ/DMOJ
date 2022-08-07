#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 2e5+5, mod=1e9+7;
pii a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+n+1);
    ll res = 0;
    ll t = 0;
    for(int i = 1; i <= n; i++){
        a[i].first%=mod;
        a[i].second%=mod;

        res += t*a[i].second%mod;
        res %= mod;
        res += (a[i].second * (a[i].first + (a[i].first*a[i].second)%mod)%mod*500000004%mod)%mod;
        res %= mod;
        t += a[i].first*a[i].second;
        t%=mod;
    }
    cout << res;
    return 0;
}