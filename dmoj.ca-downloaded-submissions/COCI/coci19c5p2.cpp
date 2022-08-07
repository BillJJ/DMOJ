#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e2+5;

int a[MM][MM];
int dis[MM][MM];
ll n, k;

int g(int u, int pa, int d);

int f(int u, int pa, ll d){
    dis[u][pa] = d; // u : pa
    if(d == k) return u;
    
    if(dis[a[u][pa]][u]){
        k -= dis[u][pa];
        k %= (dis[u][pa] - dis[a[u][pa]][u] + 1);
        return g(u, pa, 0);
    }

    return f(a[u][pa], u, d+1);
}

int g(int u, int pa, int d){
    if(d == k) return u;
    return g(a[u][pa], u, d+1);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    
    if(k <= 2){
        cout << k; return 0;
    }

    cout << f(2, 1, 2);
    
    return 0;
}