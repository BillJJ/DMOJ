#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 2e5+5, MV=1e4+5;

int ds[MM];
int find(int i){if(ds[i]<0)return i; return ds[i]=find(ds[i]);}
void merge(int u, int v){
    u = find(u),v=find(v);
    if(u==v)return;
    if(ds[u] < ds[v]) swap(u, v);
    ds[u] += ds[v];
    ds[v] = u;
}
set<int> one, en;

ll dis[MM][2]; // closest dis to 1 : n

ll close_one(int i){
    if(one.find(i) != one.end()) return 0;

    ll res = LONG_LONG_MAX;
    auto high = one.upper_bound(i);
    if(high != one.end()) res = (ll)(*high-i)*(*high-i);
    auto low = one.lower_bound(i);
    if(low != one.begin()){
        low--;
        res = min(res, (ll)(i-*low)*(i-*low));
    }
    return res;
}

ll close_en(int i){
    if(en.find(i) != en.end()) return 0;

    ll res = LONG_LONG_MAX;
    auto high = en.upper_bound(i);
    if(high != en.end()) res = (ll)(*high-i)*(*high-i);
    auto low = en.lower_bound(i);
    if(low != en.begin()){
        low--;
        res = min(res, (ll)(i-*low)*(i-*low));
    }
    return res;
}

void solve(){
    memset(ds, -1, sizeof ds);
    memset(dis, 0x3f, sizeof dis);
    one.clear(), en.clear();

    int n, m; cin >>n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        merge(a, b);
    }

    for(int i = 1; i <= n; i++){
        if(find(i) == find(1)) one.insert(i);
        if(find(i) == find(n)) en.insert(i);
    }

    ll res = LONG_LONG_MAX;
    for(int i = 1; i <= n; i++){
        dis[find(i)][0] = min(dis[find(i)][0], close_one(i));
        dis[find(i)][1] = min(dis[find(i)][1], close_en(i));
        res = min(res, dis[find(i)][0] + dis[find(i)][1]);
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin  >> t;
    while(t--) solve();

    return 0;
}