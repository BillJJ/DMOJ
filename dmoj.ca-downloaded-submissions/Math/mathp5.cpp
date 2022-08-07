#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5, mod=1e9+7;

ll fact[MM];
ll fbbb(ll a, ll b, ll x, ll y){
    if(a%b == 0) return y;
    else return fbbb(b, a%b, y, x - (a/b)*y);
}

ll mod_inv(ll x){
    ll res = fbbb(x, mod, 1, 0);
    if(res < 0) res += mod;
    return res;
}

ll nck(ll n, ll k){
    if(n < k) return 0;
    return fact[n]*mod_inv(fact[n-k])%mod*mod_inv(fact[k])%mod;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for(int i = 1; i < MM; i++){
        fact[i] = i*fact[i-1]%mod;
    }

    int n; cin >> n;
    ll res = 0;
    for(int i = 1; i <= ceil((double)n/2); i++){
        res += nck(n-i+1 - i+1, i);
        res %= mod;
    }
    cout << res;

    return 0;
}