#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int MM = 1e5+5;

vector<pip> edge;

int ds[MM];
int find(int i){
    if(ds[i] < 0) return i;
    return ds[i] = find(ds[i]);
}

void merge(int u, int v){
    u = find(u), v = find(v);
    if(ds[v] < ds[u]) swap(u, v);
    ds[u] += ds[v];
    ds[v] = u;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1, u, v, w; i < n; i++){
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }

    sort(edge.begin(), edge.end());
    memset(ds, -1, sizeof ds);
    ll res = 0;
    for(auto[w, p] : edge){
        res += ds[find(p.first)] * ds[find(p.second)] * (w+1) - 1;
        merge(p.first, p.second);
    }
    cout << res;
    return 0;
}