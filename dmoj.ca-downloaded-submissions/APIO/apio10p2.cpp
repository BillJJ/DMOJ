#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

unordered_map<int, int> edge[MM]; // weight : v

pii dis[MM]; // dis : idx
pii best; // dis, parent, left, right
void dfs(int u, int pa){
    vector<pii> c;
    for(auto[v, w] : edge[u]){
        if(v == pa) continue;
        dfs(v, u);
        c.push_back({dis[v].first+w, v});
    }
    dis[u] = {0,-1};

    sort(c.begin(), c.end(), greater<>());
    if(!c.empty()){
        dis[u] = c[0];
        best = max(best, dis[u]);
        if(c.size() >= 2 && best.first < c[0].first + c[1].first){
            best = {c[0].first + c[1].first, u};
        }
    }
    return;
}

auto cmp2nd = [](pii r, pii t){return r.second < t.second;};

void colour(int u, int pa){
    edge[u][pa] = -1, edge[pa][u] = -1;
    if(dis[u].second != -1){
        colour(dis[u].second, u);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        edge[u][v] = 1; edge[v][u] = 1;
    }

    dfs(1, -1);

    if(k == 1){
        cout << 2*(n-1) - best.first + 1; return 0;
    }

    vector<pii> c;
    for(auto[v, w] : edge[best.second]){
        if(dis[v].first > dis[best.second].first) continue;
        c.push_back({dis[v].first, v});
    }
    sort(c.begin(), c.end(), greater<>());
    colour(c[0].second, best.second); if(c.size() >= 2) colour(c[1].second, best.second);

    pii best1 = best; best={0,0};
    dfs(1, -1);
    cout << 2*(n-1) - best1.first + 1 + min(- best.first + 1, 0);

    return 0;
}