#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5, MV=1e6+5;

pii a[MM];
int bit[MV];
struct alpaca{
    int p, left, v;
};

vector<alpaca> q;

void add(int i, int v){
    for(; i < MV; i+=i&-i) bit[i] = max(bit[i], v);
}
int qmax(int i){
    int res = 0;
    for(;i > 0; i-=i&-i) res = max(res, bit[i]);
    return res;
}

map<int, int> comp;

int a2[MM*3], idx=1;
int d[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
        a2[idx++] = a[i].first;
        a2[idx++] = a[i].first-a[i].second;
        a2[idx++] = a[i].first+a[i].second;
    }
    idx--;
    sort(a2+1, a2+idx+1);
    for(int i = 1; i <= idx; i++){
        comp[a2[i]] = i;
    }
    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++){
        q.push_back({a[i].first, a[i].first+a[i].second, i});
    }
    sort(q.begin(), q.end(), [](alpaca a, alpaca b){return a.left > b.left;});

    int res = 0;
    for(int i = 1; i <= n; i++){
        while(!q.empty() && q.back().v < i && q.back().left <= a[i].first){
            add(comp[q.back().p], d[q.back().v]);
            q.pop_back();
        }

        d[i] = qmax(comp[a[i].first-a[i].second]) + 1;
        res = max(res, d[i]);
    }

    cout << res;

    return 0;
}