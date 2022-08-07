#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 2e5+5;

pii a[MM], ori[MM]; // val : id
int n;
int ds[MM];
int find(int i){if(ds[i]<0)return i; return find(ds[i]);}
void merge(int u, int v){
    u = find(u),v=find(v);
    if(u==v)return;
    if(ds[u] > ds[v]) swap(u, v);
    ds[u] += ds[v];
    ds[v] = u;
}

bool check(ll k){
    memset(ds, -1, sizeof ds);

    for(int i = 2; i <= n; i++){
        if(a[i].first - a[i-1].first <= k) merge(a[i].second, a[i-1].second);
    }

    for(int i = 1; i <= n; i++){
        if(find(a[i].second) != find(ori[i].second)) return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0);cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
        ori[i] = a[i];
    }
    sort(a+1, a+n+1);
    ll l = 0, r = a[n].first;
    while(r-l>5){
        ll mid = (r-l)/2 + l;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    for(ll i = l; i <= r; i++){
        if(check(i)){
            cout << i << "\n";
            break;
        }
    }

    return 0;
}