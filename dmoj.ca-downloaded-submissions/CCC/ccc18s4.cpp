#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e6+5;

unordered_map<int, ll> a;

int b[MM];
ll good(int x){
    if(b[x]) return b[x];

    ll res = 0;
    for(ll i = x; i >= 2; i--){
        res += good(x/i);
    }
    return b[x] = res;
}

ll f(ll x){
    if(a[x]) return a[x];

    ll res = 0;
    for(ll i = 1; i <= sqrt(x); i++){
        ll ans = f(i) * (x/i - x/(i+1));
        res += ans;
    }
    if(x / (ll)sqrt(x) == (ll)sqrt(x)){
        res -= f(x/sqrt(x));
    }
    for(ll i = 2; i <= sqrt(x); i++){
        res += f(x/i);
    }
    return a[x] = res;
}

signed main() {
    cin.sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    a[1] = 1;
    b[1] = 1;
//    f(1e6);
//    cout << "hgood: " << good(n) << "\n";
    cout << f(n);

    return 0;
}