#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 6e3+5, LOG = 17;

vector<pii> edge[MM];

vector<pii> st[LOG]; // dep, id
int occ[MM]; // idx of ^ at which node occurs
ll dis[MM];

void dfs(int u, int pa, int dep){
    st[0].push_back({dep, u});
    for(auto[v, w] : edge[u]){
        if(v == pa) continue;
        dis[v] = dis[u] + w;
        dfs(v, u, dep+1);
        st[0].push_back({dep, u});
    }
    occ[u] = st[0].size()-1;
}

void build(){
    for(int j = 1; j < LOG; j++){
        for(int i = 0; i+(1<<j-1) < st[j-1].size(); i++){
            st[j].push_back(min(st[j-1][i], st[j-1][i + (1<<j-1)]));
        }
    }
}

int lca(int u, int v){
    if(occ[u] > occ[v]) swap(u, v);
    int k = log2(occ[v]-occ[u]+1);
    return min(st[k][occ[u]], st[k][occ[v] - (1<<k)+1]).second;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int a, b, w; cin >> a >> b >> w;
        edge[a].push_back({b, w});
        edge[b].push_back({a, w});
    }

    dfs(0, -1, 0);
    build();

    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        int lc = lca(u, v);
        cout << dis[u] - dis[lc] + dis[v] - dis[lc] << "\n";
    }

    return 0;
}