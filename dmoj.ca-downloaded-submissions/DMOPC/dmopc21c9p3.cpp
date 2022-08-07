#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 3e3+5;

int dis[MM][MM];
vector<int> edge[MM];

deque<int> q;
void bfs(int u){
    q.clear();
    q.push_back(u);
    while(!q.empty()){
        int m = q.front(); q.pop_front();
        for(int v : edge[m]){
            if(dis[u][v]) continue;
            dis[u][v] = dis[u][m]+1;
            q.push_back(v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i<= n; i++){
        bfs(i);
        dis[i][i] = 0;
    }

    int q; cin >> q;
    while(q--){
        int s, t, x, u,v, y; cin >> s>> t>>x>>u>>v>>y;

        if(dis[s][t] <= x || dis[u][v] <= y){
            cout << "YES\n";
        } else if(dis[s][u]+dis[t][v]+2 <= x+y){
            cout << "YES\n";
        } else if(dis[s][v]+dis[t][u]+2 <= x+y){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

    return 0;
}