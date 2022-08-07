#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

void add(ll bit[], int i, ll v){
    for(; i <= MM; i += i&-i) bit[i] += v;
}

ll sum(ll bit[], int i){
    ll res = 0; for(;i>0;i-=i&-i) res+=bit[i];
    return res;
}

ll even[MM], odd[MM], a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i&1) add(odd, i, a[i]);
        else add(even, i, a[i]);
    }
    while(q--){
        int cmd, x, y; cin >> cmd >> x >> y;
        if(cmd == 1){
            if(x&1) add(odd, x, -a[x]+y);
            else add(even, x, -a[x]+y);
            a[x] = y;
        } else{
            if(x&1)cout << sum(odd, y) - sum(odd, x-1) << "\n";
            else cout << sum(even, y) - sum(even, x-1) << "\n";
        }
    }


    return 0;
}