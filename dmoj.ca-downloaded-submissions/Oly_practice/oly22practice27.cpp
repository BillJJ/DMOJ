#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

int nxt[MM], pre[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll l, r; cin >> l >> r;
    ll res = 0;

    while(l <= r){
        res++;
        l *= 2;
    }

    cout << res;

    return 0;
}