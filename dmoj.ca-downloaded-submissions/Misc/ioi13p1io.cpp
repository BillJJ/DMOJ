#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const int MM = 1e5+5;

vector<pii> edge[MM];

int r[MM], rd1[MM], rd2[MM]; // radius (node), dis1, dis2

int pew(int u, int p){
    int res = 0;
    for(auto[w, v] : edge[u]){
        if(v == p) continue;
        res = max(res, w+pew(v, u));
    }
    return res;
}

pii far(int u, int pa){ // node # : dis
    pii best = {u,0};
    for(auto[w, v] : edge[u]){
        if(v == pa) continue;

        pii d = far(v, u);
        if(d.second + w > best.second) best = {d.first, d.second+w};
    }
    return best;
}

vector<int> nodes;
bool putnodes = 0;
void pewpew(int u, int pa, int d[]){
    if(putnodes) nodes.push_back(u);
    for(auto[w, v] : edge[u]){
        if(v == pa) continue;
        d[v] += d[u] + w;
        pewpew(v, u, d);
    }
}

int find_r(int u){
    putnodes = 1;
    nodes.clear();
    int far1 = far(u, -1).first;
    pewpew(far1, -1, rd1);
    putnodes = 0;
    
    int far2 = far(far1, -1).first;
    pewpew(far2, -1, rd2);

    int ans = u, best = max(rd1[u],rd2[u]);
    for(int v : nodes){
        if(max(rd1[v],rd2[v]) < best){
            ans = v;
            best = max(rd1[v],rd2[v]);
        }
    }
    return ans;
}

void colour_c(int u, int p, int cd){ // fills centroid for each tree
    for(auto[w, v]:edge[u]){
        if(v != p) colour_c(v, u, cd);
    }
    r[u] = cd;
}

unordered_set<int> cs; // centroids

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, l; cin >> n >> m >> l;
    for(int i = 1,u ,v, w; i <= m; i++){
        cin >> u >> v >> w;
        u++, v++;
        edge[u].push_back({w, v});
        edge[v].push_back({w, u});
    }

    int clong=0, len=0; // centroid with longest path and len
    for(int i = 1; i <= n; i++){
        if(!r[i]){
            r[i] = find_r(i);
            colour_c(i, -1, r[i]);
            cs.insert(r[i]);
            int d = pew(r[i], -1);
            if(d >= len){
                clong = r[i], len = d;
            }
        }
    }

    // for(int c : cs){
    //     cout << "RAD: " << c << "\n";
    // }
    // for(int i= 1; i <= n; i++){
    //     cout << i << " dis1: " << rd1[i] << " . rd2: " << rd2[i] << "\n";
    // }

    cs.erase(r[clong]);
    for(int cen : cs){
        if(m == n-1) break;

        edge[cen].push_back({l, clong});
        edge[clong].push_back({l, cen});
        m++;
    }

    int f = far(1, -1).first;
    cout << pew(f, -1);

    return 0;
}