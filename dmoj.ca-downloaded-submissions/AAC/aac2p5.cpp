#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

int a[MM], n;

int dis[MM], freq[MM], seg[MM*4], leftbound[MM];

void build(int l, int r, int i){
    if(l == r) {seg[i] = dis[l]; return;}
    int mid = (l+r)/2;
    build(l, mid, i*2);
    build(mid+1, r, i*2+1);
    seg[i] = max(seg[i*2], seg[i*2+1]);
}

int query(int ql, int qr, int l, int r, int i){
    if(ql == l && qr == r){
        return seg[i];
    }
    int mid = (l+r)/2;
    if(qr <= mid) return query(ql, qr, l, mid, i*2);
    else if(ql > mid) return query(ql, qr, mid+1, r, i*2+1);
    else return max(query(ql, mid, l, mid, i*2), query(mid+1, qr, mid+1, r, i*2+1));
}

//int query(int ql, int qr, int l, int r, int i){
//    int res = 0;
//    for(; qr >= ql; qr--){
//        res = max(res, dis[qr]);
//    }
//    return res;
//}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q, ans=0; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int l = 1, r = 1; r <= n; r++){
        freq[a[r]]++;
        while(freq[a[r]] > 1){
            freq[a[l]]--;
            dis[l] = r-l;
            l++;
        }
        if(r == n){
            while(l <= n){
                dis[l] = n-l+1;
                l++;
            }
        }
    }

    for(int i = n; i >= 1; i--){
        leftbound[min(n, i+dis[i]-1)] = i;
    }
    for(int i = n; i >= 1; i--){
        if(leftbound[i] == 0) leftbound[i] = leftbound[i+1];
    }

    build(1, n, 1);
    while(q--){
        int x, y; cin >> x >> y;
        x ^= ans, y ^= ans;

        ans = query(leftbound[y], x, 1, n, 1);
        cout << ans << "\n";
    }
    

    return 0;
}