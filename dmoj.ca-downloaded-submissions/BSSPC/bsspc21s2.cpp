#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MM = 5e3+5;

struct rot{
    ll r1, c1, r2, c2, low;
} a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k, q; cin >> n >> k >> q;
    for(int i = 1; i <= k; i++){
        ll ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;
        a[i].r1 = ai, a[i].c1 = bi, a[i].r2 = ai, a[i].c2 = di, a[i].low = ci;
    }

    while(q--){
        ll qr, qc; cin >> qr >> qc;

        for(int i = k; i >= 1; i--){
            if(qr < a[i].r1 || qr > a[i].low || qc < a[i].c1 || qc > a[i].c2) continue;

            ll tqr = qr;
            qr = a[i].r1 + (a[i].c2 - qc);
            qc = a[i].c1 + (tqr - a[i].r2);
        }
        cout << (qr-1)*n+qc << "\n";
    }

    return 0;
}