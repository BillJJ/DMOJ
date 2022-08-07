#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

ll a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    ll res = 0, mod=1e9;
    for(int i = 1; i <= n; i++){
        res += i*i%mod * i*i%mod*i*i%mod;
        res %= mod;
    }
    cout << res;

    return 0;
}