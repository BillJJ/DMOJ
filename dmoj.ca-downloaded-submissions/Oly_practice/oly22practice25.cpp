#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

vector<pii> e1[MM], e2[MM]; // e1 = facing forward , e2 = backwards, for sssp from x
priority_queue<pii, vector<pii>, greater<pii>> q;
int dis1[MM], dis2[MM];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, x; cin >> n >> m >> x;
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        e1[u].push_back({w, v}), e2[v].push_back({w, u});
    }
    memset(dis1, 0x3f, sizeof dis1), memset(dis2, 0x3f, sizeof dis2);
    q.push({0, x});
    while(!q.empty()){
        auto[d, u] = q.top(); q.pop();
        if(dis1[u] < d) continue;
        dis1[u] = d;
        for(auto p : e1[u]){
            if(dis1[p.second] < d+p.first) continue;
            q.push({p.first+d, p.second});
        }
    }

    q.push({0, x});
    while(!q.empty()){
        auto[d, u] = q.top(); q.pop();
        if(dis2[u] < d) continue;
        dis2[u] = d;
        for(auto p : e2[u]){
            if(dis2[p.second] < d+p.first) continue;
            q.push({p.first+d, p.second});
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, dis1[i] + dis2[i]);
    }

    cout << res;

    return 0;
}