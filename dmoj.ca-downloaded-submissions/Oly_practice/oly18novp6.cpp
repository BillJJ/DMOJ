#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5 +5;

int a[MM];

struct node{
    int l, r, mx; ll v;
};
node seg[MM*4];

void pushup(int i){
    seg[i].mx = max(seg[i*2].mx, seg[i*2+1].mx);
    seg[i].v = seg[i*2].v + seg[i*2+1].v;
}

void build(int l, int r, int i){
    seg[i].l = l, seg[i].r = r;
    if(l == r){seg[i].mx = seg[i].v = a[l]; return;}

    int mid = (l+r)/2;
    build(l, mid, i*2);
    build(mid+1, r, i*2+1);
    pushup(i);
}

int query_max(int l, int r, int i){
    if(seg[i].l == l && seg[i].r == r) return seg[i].mx;

    int mid = (seg[i].l + seg[i].r)/2;
    if(r <= mid) return query_max(l, r, i*2);
    else if(mid < l) return query_max(l, r, i*2+1);
    else return max(query_max(l, mid, i*2), query_max(mid+1, r, i*2+1));
}

ll query_sum(int l, int r, int i){
    if(seg[i].l == l && seg[i].r == r) return seg[i].v;

    int mid = (seg[i].l + seg[i].r)/2;
    if(r <= mid) return query_sum(l, r, i*2);
    else if(mid < l) return query_sum(l, r, i*2+1);
    else return query_sum(l, mid, i*2) + query_sum(mid+1, r, i*2+1);
}

void modify(int l, int r, int i){
    if(seg[i].mx <= 1) return;

    if(seg[i].l == seg[i].r && seg[i].l == l && r == l){
        seg[i].v = sqrt(seg[i].v);
        seg[i].mx = seg[i].v;
        return;
    }

    int mid = (seg[i].l + seg[i].r)/2;
    if(r <= mid){
        modify(l, r, i*2);
    } else if(l > mid){
        modify(l, r, i*2+1);
    } else{
        modify(l, mid, i*2); modify(mid+1, r, i*2+1);
    }
    pushup(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    build(1, n, 1);

    int m; cin >> m;
    while(m--){
        int cmd, l, r; cin >> cmd >> l >> r;
        if(cmd == 1){
            cout << query_sum(l, r, 1) << '\n';
        } else{
            modify(l, r, 1);
        }
    }

    return 0;
}