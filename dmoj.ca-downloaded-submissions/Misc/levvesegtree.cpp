#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 4e5+5;

struct node{
    ll v; int mx;
    int cl, cr;
} seg[MM*60];

void pushup(int i){
    if(!seg[i].cr){
        seg[i].v = seg[seg[i].cl].v;
        seg[i].mx = seg[seg[i].cl].mx;
    } else if(!seg[i].cl){
        seg[i].v = seg[seg[i].cr].v;
        seg[i].mx = seg[seg[i].cr].mx;
    } else if(seg[i].cl && seg[i].cr){
        seg[i].mx = max(seg[seg[i].cl].mx, seg[seg[i].cr].mx);
        seg[i].v = seg[seg[i].cl].v + seg[seg[i].cr].v;
    }
}

int idx = 2;
void update(ll l, ll r, ll p, ll v, int i){
    if(l == r){
        seg[i].v = v;
        seg[i].mx = v;
        return;
    }
    ll mid = (r-l)/2 + l;
    if(p <= mid){
        if(!seg[i].cl) {seg[i].cl = idx++;}
        update(l, mid, p, v, seg[i].cl);
    } else if(p > mid){
        if(!seg[i].cr) {seg[i].cr = idx++;}
        update(mid+1, r, p, v, seg[i].cr);
    }
    pushup(i);
}

ll query_sum(ll tl, ll tr, ll l, ll r, int i){
    if(tr == r && tl == l) return seg[i].v;
    ll mid = (tr - tl)/2 + tl;
    ll res = 0;
    if(seg[i].cl && r <= mid) res += query_sum(tl, mid, l, r, seg[i].cl);
    else if(seg[i].cr && mid < l) res += query_sum(mid+1, tr, l, r, seg[i].cr);
    else{
        if(seg[i].cl) res += query_sum(tl, mid, l, mid, seg[i].cl);
        if(seg[i].cr) res += query_sum(mid+1, tr, mid+1, r, seg[i].cr);
    }
    return res;
}

ll query_max(ll tl, ll tr, ll l, ll r, int i){
    if(l == tl && r == tr) return seg[i].mx;
    ll mid = (tr- tl)/2 + tl;
    ll res = 0;
    if(seg[i].cl && r <= mid) res = max(res, query_max(tl, mid, l, r, seg[i].cl));
    else if(seg[i].cr && mid < l) res = max(res, query_max(mid+1, tr, l, r, seg[i].cr));
    else{
        if(seg[i].cl) res = max(res, query_max(tl, mid, l, mid, seg[i].cl));
        if(seg[i].cr) res = max(res, query_max(mid+1, tr, mid+1, r, seg[i].cr));
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, q; cin >> n >> q;

    ll ans = 0;
    while(q--){
        char cmd; ll l, r; cin >> cmd >> l >> r;
        l ^= ans, r ^= ans;
        if(cmd == 'C'){
            update(1, n, l, r, 1);
        } else if(cmd == 'S'){
            ans = query_sum(1, n, l, r, 1);
            cout << ans << "\n";
        } else if(cmd == 'M'){
            ans = query_max(1, n, l, r, 1);
            cout << ans << "\n";
        }
    }

    return 0;
}