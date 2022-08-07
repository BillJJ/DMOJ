#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

vector<pii> edge[MM];

ll dfs(int u){
    ll res = 0;
    for(auto [w, v] : edge[u]){
        res = max(res, w + dfs(v));
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, r; cin >> n >> r;
    for(int i = 1; i <= pow(2, n)-1; i++){
        int u, v, w, d; cin >> u >> v >> w >> d;
        edge[u].push_back({d, v});
        edge[u].push_back({0, w});
    }

    cout << dfs(1)+r;

    return 0;
}