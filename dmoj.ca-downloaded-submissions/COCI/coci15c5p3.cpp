#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5, mod=1e9+7;

ll fact[MM];
ll a[MM];

ll f(ll a, ll b, ll x, ll y){
    if(a%b == 0) return y;
    else return f(b, a%b, y, x - (a/b)*y);
}

ll mod_inv(ll x){
    ll res = f(x, mod, 1, 0);
    if(res < 0) res += mod;
    return res;
}

ll nck(ll n, ll k){
    return fact[n]*mod_inv(fact[n-k])%mod*mod_inv(fact[k])%mod;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1 ;i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);

    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = i*fact[i-1]%mod;
    }

    ll res = 0;
    for(int i = k; i <= n; i++){
        res += (nck(i-1, k-1) * a[i])%mod;
        res %= mod;
    }
    cout << res;

    return 0;
}