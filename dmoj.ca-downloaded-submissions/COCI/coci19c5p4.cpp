#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const int MM = 2e5+5, LOG=19;

map<pii, pii> cost;
vector<int> edge[MM];

vector<pii> st[LOG];
int occ[MM];

void dfs(int u, int pa, int dep){
    st[0].push_back({dep, u});
    for(int v : edge[u]){
        if(v == pa) continue;
        dfs(v, u, dep+1);
        st[0].push_back({dep, u});
    }
    occ[u] = st[0].size()-1;
}

void build_lca(){
    dfs(1, -1, 0);

    for(int j = 1; j < LOG; j++){
        for(int i = 0; i+(1<<(j-1)) < st[j-1].size(); i++){
            st[j].push_back(min(st[j-1][i], st[j-1][i + (1<<j-1)]));
        }
    }
}

int lca(int u, int v){
    if(occ[u] > occ[v]) swap(u, v);
    int k = log2(occ[v]-occ[u]+1);
    return min(st[k][occ[u]], st[k][occ[v] - (1<<k)+1]).second;
}

ll a[MM], res=0;

void push(int u, int pa){
    for(int v : edge[u]){
        if(v == pa) continue;
        push(v, u);
        a[u] += a[v];
    }

    if(u == 1) return;

    res += min(cost[{u, pa}].first*a[u], (ll)cost[{u, pa}].second);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n-1; i++){
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        int c1, c2; cin >> c1 >> c2;
        cost[{u, v}] = {c1, c2};
        cost[{v, u}] = {c1, c2};
    }
    build_lca();

    for(int i = 1; i < n; i++){
        a[i]++, a[i+1]++;
        int l = lca(i, i+1);
        a[l]-= 2;
    }

    push(1, -1);
    cout << res;

    return 0;
}