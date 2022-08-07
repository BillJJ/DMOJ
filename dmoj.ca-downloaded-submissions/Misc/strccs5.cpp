#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 2e5+5;

ll dp[MM], n;

struct node{
    ll l, r, v;
};
node seg[MM*4];

void build(int l, int r, int i){
    seg[i].l = l, seg[i].r = r;
    if(l == r) {seg[i].v = dp[l]; return;}
    int mid = (l+r)/2;
    build(l, mid, i*2);
    build(mid+1, r, i*2+1);
    seg[i].v = min(seg[i*2].v, seg[i*2+1].v);
}

void modify(int pos, ll val, int i){
    if(seg[i].l == pos && seg[i].l == seg[i].r){
        seg[i].v = val; return;
    }
    int mid = (seg[i].r+seg[i].l)/2;
    if(pos <= mid) modify(pos, val, i*2);
    else modify(pos,val, i*2+1);
    seg[i].v = min(seg[i*2].v, seg[i*2+1].v);
}

ll query(int l, int r, int i){
    if(seg[i].l==l && seg[i].r == r) return seg[i].v;
    int mid = (seg[i].l+seg[i].r)/2;
    if(r <= mid) return query(l, r, i*2);
    else if(l > mid) return query(l, r, i*2+1);
    else return min(query(l, mid, i*2), query(mid+1, r, i*2+1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    assert(1 <= n && n <= 2e5);

    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n-1; i++){
        cin >> dp[i];
        assert(1 <= dp[i] && dp[i] <= 1e9);
    }
    dp[n] = 0;
    build(1, n, 1);

    for(int i = 2; i <= n; i++){
        int l, r; cin >> l >> r;
        assert(1 <= l && l <= r && r < i);
        dp[i]+=query(l, r, 1);
        modify(i, dp[i], 1);
    }

    cout << dp[n];

    return 0;
}