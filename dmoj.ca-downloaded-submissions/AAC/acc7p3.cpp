#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct e{
    int u, v, w;
    e(int u, int v, int w): u(u), v(v), w(w){};
};

ll n;
vector<int> f;
vector<e> edge;

ll dset[100005];

ll find(ll i){
    if(dset[i] < 0) return i;

    dset[i] = find(dset[i]);
    return dset[i];
}

void merge(ll u, ll v){
    if(dset[v] < dset[u]){
        swap(u, v);
    }
    dset[u] += dset[v];
    dset[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    fill(begin(dset), end(dset), -1);

    ll m; cin >> n >> m;
    unsigned long long total = 0;
    for(ll i = 0; i < n; i++){
        ll friendliness; cin >> friendliness;
        f.push_back(friendliness);
    }

    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        a = find(a-1); b = find(b-1);
        if(a == b) continue;
        merge(a, b);
    }

    for(int i = 0; i < n-1; i++){
        edge.push_back(e(i, i+1, f[i+1] - f[i]));
    }

    auto comp = [](e a, e b){return a.w < b.w;};
    sort(begin(edge), end(edge), comp);

    for(e p : edge){
        int a = find(p.v), b = find(p.u);
        if(a == b) continue;

        merge(a, b);
        total += p.w;
    }


    cout << total << '\n';
}