#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip; // w : {u, v}

const int MM = 2e5+5;
vector<pip> edge;
int ds[MM], powed[MM];

int find(int i){
    if(ds[i] < 0) return i;
    ds[i] = find(ds[i]);
    return ds[i];
}

void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(ds[v] < ds[u]) swap(u, v);
    ds[u] += ds[v];
    ds[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        edge.push_back({x, {-1, i}});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int w; cin >> w;
            if(i == j) continue;
            edge.push_back({w, {i, j}});
        }
    }
    sort(edge.begin(), edge.end());

    int res = 0;
    memset(ds, -1, sizeof ds);
    for(auto[w, p] : edge){
        auto[u, v] = p;

        if(u == -1){
            if(powed[find(v)]) continue;
            res += w;
            powed[find(v)] = 1;
        } else{
            if(powed[find(u)] && powed[find(v)] || find(u) == find(v)) continue;

            res += w;
            if(powed[find(u)] || powed[find(v)]){
                merge(u, v);
                powed[find(u)] = 1;
            } else{
                merge(u, v);
            }
        }
    }

    cout << res;

    return 0;
}