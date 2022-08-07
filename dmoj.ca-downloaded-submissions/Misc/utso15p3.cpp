// thansk for teh free points!!

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5, mod=1e9+7;

ll dpa[MM], dpb[MM], dpc1[MM], dpc2[MM], dpd[MM], dpf[MM];
ll f(int n){
    if(dpf[n]) return dpf[n];
    if(n <= 0) return 0;
    else if(n == 1) return 1;
    return dpf[n] = (f(n-1) + f(n-3))%mod;
}

ll a(int n), b(int n), c1(int n), c2(int n), d(int n);

ll a(int n){
    if(dpa[n]) return dpa[n];
    if(n <= 0) return 0;
    else if(n == 1) return 1;
    return dpa[n] = (a(n-1) + b(n-2) + c1(n-3))%mod;
}

ll b(int n){
    if(dpb[n]) return dpb[n];

    if(n <= 0) return 0;
    return dpb[n] = ( a(n-2) + c2(n-3) + d(n-1) + d(n-3))%mod;
}

ll c1(int n){
    if(dpc1[n]) return dpc1[n];
    if(n <= 0) return 0;
    return dpc1[n] = ( a(n-2) + c2(n))%mod;
}

ll c2(int n){
    if(dpc2[n]) return dpc2[n];

    if(n <= 0) return 0;
    return dpc2[n] = (a(n-1) + a(n-2) + c2(n-3) + d(n-1) + d(n-3))%mod;
}

ll d(int n){
    if(dpd[n]) return dpd[n];

    if(n <= 0) return 0;
    return dpd[n]=(a(n) + b(n-1))%mod;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m; cin >> n >> m;
    if(m == 1){
        cout << 1;
    } else if(m == 2){
        cout << f(n);
    } else{
        cout << a(n);
    }

    return 0;
}