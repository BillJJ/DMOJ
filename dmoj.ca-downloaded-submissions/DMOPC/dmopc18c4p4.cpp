#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MM = 2e5+5;

ll psa[MM], bit[MM], a[MM];
pll sors[MM];

struct req{
    ll i, l, r, k, ans;  
} qs[MM];

void add(ll v, ll i){
    for(;i<MM;i+=i&-i) bit[i] += v;
}
ll sumr(ll i){
    ll res = 0;
    for(;i>0;i-=i&-i) res+=bit[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("aocin.txt", "r", stdin);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; psa[i] = a[i] + psa[i-1];
        sors[i] = {a[i], i};
    }
    sort(sors+1, sors+n+1);
    for(int i = 1; i <= q; i++){
        cin >> qs[i].l >> qs[i].r >> qs[i].k;
        qs[i].i = i;
    }
    sort(qs+1, qs+1+q, [](req x, req y){return x.k < y.k;});
    sors[n+1].first = INT_MAX;
    for(int i = 1, idx = 1; i <= q; i++){
        while(sors[idx].first < qs[i].k){
            add(sors[idx].first, sors[idx].second);
            idx++;
        }
        qs[i].ans = psa[qs[i].r] - psa[qs[i].l-1] - (sumr(qs[i].r) - sumr(qs[i].l-1))*2;
    }

    sort(qs+1, qs+q+1, [](req x, req y){return x.i < y.i;});
    
    for(int i = 1; i <= q; i++){
        cout << qs[i].ans << "\n";
    }

    return 0;
}