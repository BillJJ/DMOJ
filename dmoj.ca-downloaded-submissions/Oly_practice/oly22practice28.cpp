#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

ll seg[MM*4], lazy[MM*4], n, q;
void push_down(int i){
    seg[i*2] += lazy[i], seg[i*2+1] += lazy[i];
    lazy[i*2] += lazy[i], lazy[i*2+1] += lazy[i];
    lazy[i] = 0;
}
void push_up(int i){
    seg[i] = seg[i*2] + seg[i*2+1];
}
void add(int l, int r, int ql, int qr, int v, int i){
    if(l == ql && r == qr){
        seg[i] += v; lazy[i] += v; return;
    }
    push_down(i);
    int mid = (l+r)/2;
    if(qr <= mid) add(l, mid, ql, qr, v, i*2);
    else if(ql > mid) add(mid+1, r, ql, qr, v, i*2+1);
    else{
        add(l, mid, ql, mid, v, i*2);
        add(mid+1, r, mid+1, qr, v, i*2+1);
    }
    push_up(i);
}
ll query(int l, int r, int ql, int qr, int i){
    if(l == ql && r == qr) return seg[i];
    int mid = (l+r)/2;
    push_down(i);
    if(qr <= mid) return query(l ,mid, ql, qr, i*2);
    else if(ql > mid) return query(mid+1, r, ql, qr, i*2+1);
    else{
        return query(l, mid, ql, mid, i*2) + query(mid+1, r, mid+1, qr, i*2+1);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            add(1, n, l, r, k, 1);
        }else{
            int x; cin >> x;
            cout << query(1, n, x, x, 1) << "\n";
        }
    }

    return 0;
}