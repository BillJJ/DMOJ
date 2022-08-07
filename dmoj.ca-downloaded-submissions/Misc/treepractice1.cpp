#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

vector<pii> edge[MM];
int dis1[MM], dis2[MM];

pii pew(int u, int pa){ // dis : node
    pii best = {0, u};
    for(auto[w, v] : edge[u]){
        if(v == pa) continue;

        pii p = pew(v, u);
        if(w + p.first > best.first) best = {w+p.first, p.second};
    }
    return best;
}

void pew(int u, int pa, int dis[]){
    for(auto[w, v] : edge[u]){
        if(v == pa) continue;

        dis[v] = dis[u] + w;
        pew(v, u, dis);
    }
    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        edge[u].push_back({w, v});
        edge[v].push_back({w, u});
    }

    cout << pew(pew(1, -1).second, -1).first << "\n";
    
    int far1 = pew(1, -1).second;
    int far2 = pew(far1, -1).second;

    pew(far1, -1, dis1);
    pew(far2, -1, dis2);

    int res = INT_MAX;
    for(int i = 1; i <= n; i++){
        int x = max(dis1[i], dis2[i]);
        res = min(res, x);
    }

    cout << res;
    
    return 0;
}