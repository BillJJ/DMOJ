#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;

int ds[MM], vis[MM];

int find(int i){
    if(ds[i] < 0) return i;
    ds[i] = find(ds[i]);
    return ds[i];
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;

    ds[b] += ds[a];
    ds[a] = b;
}

void solve(){
    int n; cin >> n;
    memset(ds, -1, sizeof ds);

    for(int i = 1; i <= n; i++){
        int b; cin >> b;
        merge(i, b);
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[find(i)]) res++;
        vis[find(i)] = 1;
    }
    cout << res;
}

int main()  {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
    cout << " ";
    memset(vis, 0, sizeof vis);
    solve();

    return 0;
}