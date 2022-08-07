#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e3+5;
vector<int> edge[MM];
int pa[MM];
bool vis[MM];
vector<pii> node; // depth : i

void dfs(int u, int dep){
    vis[u] = 1;
    node.push_back({dep, u});
    for(int v : edge[u]){
        if(!vis[v]) {
            pa[v] = u;
            dfs(v, dep+1);
        }
    }
}

void colour(int p, int u, int left){
    vis[u] = 1;
    if(left == 0) return;
    for(int v : edge[u]){
        if(v != p) colour(u, v, left-1);
    }
}

int needed(int len){
    memset(vis, 0, sizeof vis);
    int res = 0;
    for(pii u : node){
        if(vis[u.second]) continue;

        int par = u.second;
        for(int i = 0; i < len; i++) par = pa[par];

        res++;
        colour(0, par, len);
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, s; cin >> n >> s;
    for(int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        edge[a].push_back(b); edge[b].push_back(a);
    }
    pa[1]=1;
    dfs(1, 1);
    sort(node.begin(), node.end(), greater<pii>()); // greatest depth first

    int l = 0, r = n;
    while(l < r){
        int mid = (l+r)/2;
        if(needed(mid) <= s) r = mid;
        else l = mid+1;
    }

    cout << (l+r)/2;

    return 0;
}