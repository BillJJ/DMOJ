#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2005, mod = 1e9+7;
ll bit[MM][MM];

void add(int lane, int i, int v){
    for(; i<=MM; i += i&-i){
        bit[lane][i] = (bit[lane][i]+v)%mod;
    }
}

ll sum(int lane, int i){
    ll res = 0;
    for(; i > 0; i-=i&-i)
        res = (res+bit[lane][i])%mod;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    ll total = 0;
    while(q--){
        int cmd, r, c, x;
        cin >> cmd >> r >> c >> x;
        if(cmd == 1){
            add(r+c, c, x);
        }
        else{
            total = (total + sum(r+c, c+x) - sum(r+c, c-1))%mod;
        }
    }
    cout << total%mod;
}