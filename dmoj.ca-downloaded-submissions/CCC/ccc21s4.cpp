#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 2e5+5;

vector<int> edge[MM];

int station[MM];
int dis[MM];
deque<int> q;

int seg[MM*2], n;

void build(){
    for(int i = n-1; i > 0; i--) seg[i] = min(seg[i*2], seg[i*2+1]);
}

void modify(int p, int v){
    for(seg[p+=n] += v; p>1; p/=2)
        seg[p/2] = min(seg[p], seg[p^1]);
}

int query(int l, int r){
    r++;
    int res = INT_MAX;
    for(l+=n, r+=n; l<r; l/=2, r/=2){
        if(l&1) res = min(res, seg[l++]);
        if(r&1) res = min(res, seg[--r]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int w, d; cin >> n >> w >> d;
    for(int i = 0, a, b; i < w; i++){
        cin >> a >> b;
        edge[b].push_back(a);
    }

    memset(dis, 0x3f, sizeof dis);
    q.push_back(n);
    dis[n] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        for(int v : edge[u]){
            if(dis[v] <= dis[u]+1) continue;
            dis[v] = dis[u]+1;
            q.push_back(v);
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> station[i];
        seg[i+n-1] = dis[station[i]] + i-1;
    }

    build();

    while(d--){
        int x, y; cin >> x >> y;
        modify(x-1, -dis[station[x]] + dis[station[y]]);
        modify(y-1, -dis[station[y]] + dis[station[x]]);
        swap(station[x], station[y]);

        cout << query(0, n-1) << '\n';
    }

    return 0;
}