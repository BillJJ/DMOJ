#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

unordered_map<int, int> ds;
int find(int i){
    if(ds[i] < 0) return i;
    return ds[i] = find(ds[i]);
}
void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(ds[u] < ds[v]) swap(u, v);
    ds[u] += ds[v];
    ds[v] = u;
}
void solve(){
    ds.clear();
    int n; cin >> n;
    vector<pii> bad;
    for (int i = 1; i <= n; ++i) {
        int u, v, e; cin >> u >> v >> e;
        if(ds.find(u) == ds.end()) ds[u] = -1;
        if(ds.find(v) == ds.end()) ds[v] = -1;

        if(e == 1) merge(u, v);
        else bad.push_back({u, v});
    }

    for(auto[u, v] : bad){
        if(find(u) == find(v)){
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";

    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}