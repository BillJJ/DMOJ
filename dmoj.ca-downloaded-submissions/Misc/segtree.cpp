#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int seg[MAXN*2];
int n;

// https://codeforces.com/blog/entry/18051
void build(){
    for(int i = n-1; i > 0; --i) seg[i] = min(seg[i<<1], seg[i<<1|1]);
}

void modify(int p, int v){
    for(seg[p += n] = v; p > 1; p>>=1) seg[p>>1] = min(seg[p], seg[p^1]);
}

int query(int l, int r){
    int res = INT_MAX;
    for(l += n, r+= n; l < r; l>>=1, r>>=1){
        if(l&1) res = min(res, seg[l++]);
        if(r&1) res = min(res, seg[--r]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    memset(seg, 0x3f, sizeof seg);

    int m; cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> seg[n+i];

    build();
    while(m--){
        char cmd; cin >> cmd;
        int x, y; cin >> x >> y;
        if(cmd == 'M'){
            modify(x, y);
        }else{
            cout << query(x, y+1) << '\n';
        }
    }

    return 0;
}