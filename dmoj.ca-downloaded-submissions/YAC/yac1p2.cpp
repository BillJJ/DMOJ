#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

vector<int> edge[MM];
char c[MM];

ll res;
ll b[MM], w[MM];

void check(int u, int pa){
    for(int v : edge[u]){
        if(c[v]=='B')b[u]++;
        else w[u]++;
    }
    if(c[u] == 'B') res -= w[u]*(w[u]-1)/2 + w[u]*b[u];
    else res -= b[u]*(b[u]-1)/2 + w[u]*b[u];

    for(int v : edge[u]){
        if(v == pa) continue;
        check(v, u);
    }

    for(int v : edge[u]){
        if(v == pa) continue;

        if(c[u] == 'W' && c[v] == 'W'){
            res -= b[u]*b[v];
        } else if(c[u] == 'W' && c[v] == 'B'){
            res -= (b[u]-1)*(w[v]-1) + w[u]*b[v];
        } else if(c[u] == 'B' && c[v] == 'W'){
            res -= b[u]*w[v] + (w[u]-1)*(b[v]-1);
        } else{
            res -= w[u] * w[v];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    for(int i = 1; i <= n ;i++){
        cin >> c[i];
    }
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    res= n*(n-1)/2 - (n-1);

    check(1, -1);

    cout << res << "\n";

    return 0;
}