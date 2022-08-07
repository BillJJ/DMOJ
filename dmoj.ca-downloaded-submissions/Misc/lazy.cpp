#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

ll a[MM], seg[MM*4], lazy[MM*4];
bool mark[MM*4];
void pushup(int i){
    seg[i] = min(seg[i*2], seg[i*2+1]);
}
void pushdown(int i){
    // add
    seg[i*2] += lazy[i], lazy[i*2] += lazy[i];
    seg[i*2+1] += lazy[i], lazy[i*2+1] += lazy[i];
    lazy[i] = 0;

    // assign
    if(mark[i]){
        seg[i*2] = seg[i], seg[i*2+1] = seg[i];
        mark[i*2] = mark[i*2+1] = 1;
        mark[i] = 0;
    }
}

void build(int l, int r, int i){
    if(l == r) {seg[i] = a[l]; return;}
    int mid = (l+r)/2;
    build(l, mid, i*2), build(mid+1, r, i*2+1);
    pushup(i);
}

void add(int l, int r, int ql, int qr, int v, int i){
    if(ql == l && qr == r){
        seg[i] += v;
        lazy[i] += v;
        return;
    }
    pushdown(i);
    int mid = (l+r)/2;
    if(qr <= mid) add(l, mid, ql, qr, v, i*2);
    else if(mid < ql) add(mid+1, r, ql, qr, v, i*2+1);
    else add(l, mid, ql, mid, v, i*2), add(mid+1, r, mid+1, qr, v, i*2+1);
    pushup(i);
}

void assign(int l, int r, int ql, int qr, int v, int i){
    if(ql == l && qr == r){
        seg[i] = v;
        mark[i] = 1;
        return;
    }
    pushdown(i);
    int mid = (l+r)/2;
    if(qr <= mid) assign(l, mid, ql, qr, v, i*2);
    else if(mid < ql) assign(mid+1, r, ql, qr, v, i*2+1);
    else assign(l, mid, ql, mid, v, i*2), assign(mid+1, r, mid+1, qr, v, i*2+1);
    pushup(i);
}

ll query(int l, int r, int ql, int qr, int i){
    if(l == ql && qr == r){
        return seg[i];
    }
    pushdown(i);
    int mid = (l+r)/2;
    if(qr <= mid) return query(l, mid, ql, qr, i*2);
    else if(mid < ql) return query(mid+1, r, ql, qr, i*2+1);
    else{
        return min(query(l, mid, ql, mid, i*2), query(mid+1, r, mid+1,qr, i*2+1));
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    build(1, n, 1);
    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int l, r, v; cin >> l >> r >> v;
            add(1, n, l, r, v, 1);
        } else if(cmd == 2){
            int l, r, v; cin >> l >> r >> v;
            assign(1, n, l, r, v, 1);
        } else{
            int l, r; cin >> l >> r;
            cout << query(1, n, l, r, 1) << "\n";
        }
    }

    return 0;
}