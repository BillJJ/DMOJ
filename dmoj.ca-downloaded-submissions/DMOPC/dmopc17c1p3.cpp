#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM=1e5+5, mod=1e9+7;

vector<pii> edge[MM];

ll dis[MM];
priority_queue<pii, vector<pii>, greater<pii>>q;
signed main() {
    cin.sync_with_stdio(0); cin.tie(0);

    ll n, m; cin >> n >> m;
    for(int i = 1, a, b, t; i <= m; i++){
        cin >> a >> b >> t;
        if(t == 0){
            edge[a].push_back({1, b});
            edge[b].push_back({1, a});
        } else{
            edge[a].push_back({MM, b});
            edge[b].push_back({MM, a});
        }
    }

    memset(dis, 0x3f, sizeof dis);
    q.push({0, 1});
    while(!q.empty()){
        auto[w, u] = q.top(); q.pop();
        if(dis[u] < w) continue;
        dis[u] = w;
        for(pii p : edge[u]){
            if(dis[p.second] < (dis[u] + p.first)) continue;
            q.push({dis[u]+p.first, p.second});
            dis[p.second] = dis[u]+p.first;
        }
    }

    if(dis[n] == 4557430888798830399){
        cout << -1;
    } else{
        cout << dis[n]/MM << " " << dis[n]%MM + dis[n]/MM;
    }

    return 0;
}