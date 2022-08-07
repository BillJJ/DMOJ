#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int dis[MM];
vector<int> edge[MM];
deque<int> q;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        edge[v].push_back(u);
    }
    if(edge[1].empty()) dis[1] = 1;

    q.push_back(1);
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        for(int v : edge[u]){
            if(dis[v]) continue;
            dis[v] = dis[u]+1;
            q.push_back(v);
        }
    }

    for(int i = 1; i <= n; i++){
        if(dis[i]) cout << "1";
        else cout << "0";
    }

    return 0;
}