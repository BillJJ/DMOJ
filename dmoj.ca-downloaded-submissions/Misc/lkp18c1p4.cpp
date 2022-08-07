#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM=1e5+5, mod=1e9+7;

ll n, m, A, B, C;

struct eg{
    ll w, v, lvl;
};
vector<eg> edge[MM];

ll dis[MM];
bool reachable(int pass){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    memset(dis, 0x3f, sizeof dis);
    dis[A] = 0;
    q.push({0, A});
    while(!q.empty()){
        auto[w, u] = q.top(); q.pop();
        if(dis[u] < w) continue;

        if(u == B){
            return w < C;
        }
        for(eg v : edge[u]){
            if(v.lvl > pass || dis[v.v] <= dis[u]+v.w) continue;

            q.push({dis[u]+v.w, v.v});
            dis[v.v] = dis[u]+v.w;
        }
    }
    return false;
}

signed main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        edge[u].push_back({w, v, i});
        edge[v].push_back({w, u, i});
    }

    cin >> A >> B >> C;
    if(A == B){
        cout << 0; return 0;
    }
    if(!reachable(m)){
        cout << -1; return 0;
    }

    int l = 1, r = m;
    while(r-l > 5){
        ll mid = (l+r)/2;
        if(reachable(mid)) r = mid;
        else l=mid+1;
    }

    for(int i = l; i <= r; i++){
        if(reachable(i)){
            cout << i; break;
        }
    }

    return 0;
}