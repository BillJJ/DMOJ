#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MM = 1e5+5;

char type[MM];
int ds[MM];

int find(int i){
    if(ds[i] < 0) return i;
    ds[i] = find(ds[i]);
    return ds[i];
}

void merge(int u, int v){
    u = find(u), v = find(v);
    if(ds[u] > ds[v]) swap(u, v);
    ds[u] += ds[v];
    ds[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    memset(ds, -1, sizeof ds);
    for(int i = 1; i <= n; i++){
        cin >> type[i];
    }

    for(int i = 1; i <n ;i++){
        int a, b; cin >> a >> b;
        if(type[a] == type[b]) merge(a, b);
    }

    for(int i = 0; i < m; i++){
        int a, b; char c; cin >> a >> b >> c;
        if(type[find(a)] == c || type[find(b)] == c || find(a) != find(b)) cout << 1;
        else cout << 0;
    }

    return 0;
}