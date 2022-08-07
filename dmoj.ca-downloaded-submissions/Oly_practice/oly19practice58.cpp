#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    ll res = 1;
    for(ll i = 2; i <= n; i++){
        ll x = i*(i-1)/2;
        if(x >= n) break;
        if((n-x) % i == 0) res++;
    }
    cout << res;

    return 0;
}