#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

ll v[MM], ds[MM];

int find(int i){
    if(ds[i] < 0) return i;
    ds[i] = find(ds[i]);
    return ds[i];
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;

    if(ds[b] < ds[a]) swap(a, b);
    ds[a] += ds[b];
    ds[b] = a;
    v[a] += v[b];
}

int main()  {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    memset(ds, -1, sizeof ds);

    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int a, b; cin >> a >> b;
            merge(a, b);
        } else if(cmd == 2){
            int a; cin >> a; a=find(a);
            cout << -ds[a] << '\n';
        } else if(cmd == 3){
            int a; cin >> a;
            cout << v[find(a)] << '\n';
        }
    }

    return 0;
}