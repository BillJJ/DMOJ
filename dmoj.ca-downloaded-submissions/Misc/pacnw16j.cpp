#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 2e5+5, LOG = 19;

ll st[LOG][MM];

ll query(int l, int r){
    int len = log2(r-l+1);
    return min(st[len][l], st[len][r-(1<<len)+1]);
}

int next_lowest(int l, int r, ll v){ // returns index of next lowest number
    while(l < r){
        // cout << l << " c\n";
        int mid = (r-l)/2 + l;
        if(query(l, mid) <= v){
            r = mid;
        } else{
            l = mid+1;
        }
    }
    return (l+r)/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> st[0][i];
    }

    for(int j = 1; j < LOG; j++){
        for(int i = 1; i + (1<<j-1) <= n; i++){
            st[j][i] = min(st[j-1][i], st[j-1][i+(1<<j-1)]);
        }
    }

    while(q--){
        ll v, l, r; cin >> v >> l >> r;
        
        while(query(l, r) <= v){
            l = next_lowest(l, r, v);
            v %= st[0][l];
        }
        cout << v << "\n";
    }

    return 0;
}