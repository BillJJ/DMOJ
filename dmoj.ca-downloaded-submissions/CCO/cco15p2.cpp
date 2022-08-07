#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 18, MV=1e6;

vector<pii> edge[MM];
int n, m, dp[18][200000];

int dfs(int i, int vis){
    if(dp[i][vis] >= 0) return dp[i][vis];
    if(i == n-1) return dp[i][vis]=0;

    int res = -INT_MAX;
    for(auto[w, v] : edge[i]){
        if(!(vis & 1<<v)){
            res = max(res, w+dfs(v, vis | 1<<i));
        }
    }
    return dp[i][vis]=res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    memset(dp, -0x3f, sizeof dp);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge[u].push_back({w, v});
    }

    cout << dfs(0, 1);

    return 0;
}