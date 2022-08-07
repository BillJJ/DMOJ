#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=3e2+5;

vector<pii> edge[MM];

int dis[MM][MM];

signed main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m , t; cin >> n >> m >> t;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge[u].push_back({w, v});
    }

    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; i++){
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, i});
        while(!q.empty()){
            auto[w, u] = q.top(); q.pop();
            if(dis[i][u] < w) continue;
            dis[i][u] = w;
            for(pii p : edge[u]){
                if(dis[i][p.second] > max(p.first, dis[i][u])) {
                    q.push({max(p.first, dis[i][u]), p.second});
                }
            }
        }
    }

    while(t--){
        int a, b; cin >> a >> b;
        cout << (dis[a][b]>1e6 ?-1:dis[a][b]) << "\n";
    }

    return 0;
}