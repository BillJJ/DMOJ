#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

ll a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, q, h;
    cin >> n >> q >> h;
    for(int i = 1, x; i <= n; i++){
        cin >> x; cin >> a[i];
        if(x > h){
            a[i] = a[i-1];
        } else a[i] += a[i-1];

    }
    ll res = 0;
    while(q--){
        int l, r; cin >> l >> r;
        res = max(res, a[r]-a[l-1]);
    }
    cout << res;

    return 0;
}