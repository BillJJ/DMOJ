#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int ll
typedef pair<int, int> pii;

const int MM = 1e6+5, mod=1e9+7;

ll a[MM][2];

ll mod_exp(ll a, ll n, ll m) {
    ll r = 1;

    while (n > 0) {
        if (n & 1)
            r = r*a%m;
        a = a*a%m;
        n >>= 1;
    }
    return r;
}

#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll n, m; su(n); su(m);
    for(int j = 0; j < 2; j++)
        for(int i = 1; i <= n; i++) su(a[i][j]);

    ll emp[2]={};
    int mi[2]={}, mx[2]={INT_MAX,INT_MAX};
    for(int i = 1; i <= n; i++){
        if(a[i][0] && a[i][1]){
            mi[i%2] = max(mi[i%2], a[i][0] + a[i][1]);
            mx[i%2] = min(mx[i%2], a[i][0] + a[i][1]);
        } else if(!a[i][0] && !a[i][1]){
            mi[i%2] = max(mi[i%2], 2LL);
            mx[i%2] = min(mx[i%2], 2*m);
            emp[i%2]++;
        } else{
            mi[i%2] = max(mi[i%2], a[i][0]+a[i][1] + 1);
            mx[i%2] = min(mx[i%2], a[i][0]+a[i][1]+m);
        }
    }

    // cout << "odd min/max: " << mi[1] << " " << mx[1] << "\n";
    // cout << "even min/max: " << mi[0] << " " << mx[0] << '\n';

    for(int i = 1; i <= n; i++){
        int hi = mx[i%2], lo = mi[i%2], t=a[i][0], b=a[i][1];
        if(t && b){
            if(t+b > hi || t+b < lo){cout << 0; return 0;}
        } else if(!t && !b){
            if(2*m < lo || 2 > hi){cout << 0; return 0;}
        } else{
            if(t+b+m < lo || t+b+1 > hi){cout << 0; return 0;}
        }
    }

    ll res[2]={};
    
    for(int _ = 0; _ < 2; _++){
        if(!emp[_]){
            res[_] += mx[_]-mi[_]+1; continue;
        }
        for(ll x = mi[_]; x <= mx[_]; x++){            
            ll start = max(1LL, x-m);
            ll end = x-start;
            res[_] = (res[_] + mod_exp((end-start+1),emp[_],mod))%mod;
        }
    }

    // cout << res[0] << " " << res[1] << " n\n";
    // cout << emp[0] << " emp\n";
    
    cout << (res[0]*res[1])%mod;
    
    return 0;
}