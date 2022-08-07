#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

int nxt[MM], pre[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 1; i<= n; i++){
        nxt[i] = i+1;
        pre[i] = i-1;
    }
    pre[1] = 0;
    nxt[0] = 1;

    while(q--){
        int l, r, k; cin >> l >> r >> k;

        nxt[pre[l]] = nxt[r], pre[nxt[r]] = pre[l];
        nxt[r] = nxt[k], pre[nxt[k]] = r;
        nxt[k] = l, pre[l] = k;
    }

    int p = 0;
    for(int i = 1; i <= n; i++){
        p = nxt[p];
        cout << p << " ";
    }

    return 0;
}