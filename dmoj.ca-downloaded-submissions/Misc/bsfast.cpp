#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;
int seg[MM*4];

void build(int l, int r, int i){
    if(l == r){cin >> seg[i]; return;}
    int mid = (l+r)/2;
    build(l, mid, i*2);
    build(mid+1, r, i*2+1);
    seg[i] = min(seg[i*2], seg[i*2+1]);
}

void modify(int pos, int v, int l, int r, int i){
    if(l == r && pos == l){seg[i] = v; return;}
    int mid = (r+l)/2;
    if(pos <= mid) modify(pos, v, l, mid, i*2);
    else modify(pos, v, mid+1, r, i*2+1);
    seg[i] = min(seg[i*2], seg[i*2+1]);
}

int query(int ql, int qr, int k, int l, int r, int i){
    if(seg[i] >= k) return -1;
    if(l == r){ return seg[i]<k? l : -1;}

    int mid = (l+r)/2;
    if(qr <= mid) return query(ql, qr, k, l, mid, i*2);
    else if(mid < ql) return query(ql, qr, k, mid+1, r, i*2+1);
    int left = query(ql, mid, k, l, mid, i*2);
    if(left == -1) return query(mid+1, qr, k, mid+1, r, i*2+1);
    else return left;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q, ans=0; cin >> n >> q;
    build(1, n, 1);
    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int p, x; cin >> p >> x;
            p^=ans, x^=ans;
            modify(p, x, 1, n, 1);
        } else{
            int l, r, k; cin >> l >> r >> k;
            l^=ans, r^=ans, k^=ans;
            ans = query(l, r, k, 1, n, 1);
            cout << ans << "\n";
        }
    }

    return 0;
}