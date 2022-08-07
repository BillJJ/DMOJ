#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dset[100005];

int find(int i){
    if(dset[i] < 0) return i;
    dset[i] = find(dset[i]);
    return dset[i];
}

void merge(int u, int v){

    u = find(u), v = find(v);
    if(u == v) return;
    if(dset[u] > dset[v])
        swap(u, v);

    dset[u] += dset[v];
    dset[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;

    fill(begin(dset), begin(dset) + n + 1, -1);

    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int u, v; cin >> u >> v;
            merge(u, v);
        }
        else{
            int x; cin >> x;
            cout << -dset[find(x)] << '\n';
        }
    }

    return 0;
}