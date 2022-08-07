#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e3+5;

vector<int> edge[MM];

int dp[MM], w[MM], vis[MM];
int dfs(int u){
    if(vis[u] == -1) return dp[u] = -1;
    if(dp[u]) return dp[u];

    int res = 0;
    for(int v: edge[u]){
        if(dfs(v) < 0) return dp[u]=-1;
        res = max(res, dfs(v));
    }
    res += w[u];
    return dp[u] = res;
}

int go(int u){ // -1 bad, 2 = good
    if(vis[u]) return vis[u];

    vis[u] = 1;
    for(int v : edge[u]){
        go(v);
        if(vis[v] == 1||vis[v]==-1) return vis[u] = -1;
    }
    return vis[u] = 2;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n;i ++){
        int t; cin >> w[i] >> t;
        while(t--){
            int v; cin >> v;
            edge[i].push_back(v);
        }
    }

    for(int i = 1; i <= n; i++){
        go(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(dfs(i), ans);
    }

    cout << ans << "\n";

    return 0;
}