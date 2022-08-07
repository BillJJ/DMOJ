#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

vector<int> edge[MM]; // directed graph from taller to shorter
int vis[MM];

bool go(int u, int dest){
    vis[u] = 1;
    if(u == dest) return true;
    for(int v : edge[u]){
        if(!vis[v])
            if(go(v, dest)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    assert(m != 1e7);
    while(m--){
        int a, b; cin >> a >> b; // a taller than b
        edge[a].push_back(b);
    }

    int a, b; cin >> a >> b;
    if(go(a, b)){
        cout << "yes";
        return 0;
    }
    memset(vis, 0, sizeof vis);
    if(go(b, a)){
        cout << "no";
    } else{
        cout << "unknown";
    }

    return 0;
}