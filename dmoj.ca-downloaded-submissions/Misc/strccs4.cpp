#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 2e5+5;

int a[MM], n, k;
vector<int> edge[MM];

bool vis[MM];

int dfs(int i){
    if(vis[i] || a[i] > k) return 0;

    int res = 1;
    vis[i] = 1;
    for(int v : edge[i]){
        if(!vis[v])
            res += dfs(v);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        int comp = dfs(i);
        res += comp*(comp-1)/2;
    }
    cout << res;
}