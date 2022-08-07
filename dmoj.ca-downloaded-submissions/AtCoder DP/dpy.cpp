#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 3e3+5, MV=2e5+5, mod=1e9+7;

struct b{
    ll r, c, v;
}a[MM];

ll f[MV];

ll inv(ll A, ll M){
    ll y = 0, x = 1; ll MOD = M;
    if(M == 1)  return 0;
    while(A > 1){
        ll Q = A/M; ll temp = M;
        M = A%M; A = temp;
        temp = y; y = x-Q*y; x = temp;}
    if(x < 0) x += MOD;
    return x % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int h, w; cin >> h >> w;
    int n; cin >> n;
    for(int i = 1, r, c; i <= n; i++){
        cin >> r >> c;
        a[i] = {r, c, 0};
    }

    sort(a+1, a+n+1, [](b x, b y){if(x.r == y.r) return x.c < y.c; return x.r < y.r;});
    a[n+1] = {h, w, 0}; n++;

    f[0] = 1;
    for(int i = 1; i < MV; i++){
        f[i] = (f[i-1]*i) % mod;
    }

    for(int i = 1; i <= n; i++){
        ll n =a[i].r-1+a[i].c-1, k = a[i].c-1;
        a[i].v = (f[n]*inv(f[k], mod)%mod*inv(f[n-k], mod)%mod);
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i].r > a[j].r || a[i].c > a[j].c) continue;
            
            ll n = (a[j].r - a[i].r + a[j].c - a[i].c);
            ll k = a[j].c - a[i].c;
            a[j].v -= a[i].v * (f[n]*inv(f[k], mod)%mod*inv(f[n-k], mod)%mod)%mod;
            a[j].v = (a[j].v+mod)%mod;
        }
    }

    cout << a[n].v;
    
    return 0;
}