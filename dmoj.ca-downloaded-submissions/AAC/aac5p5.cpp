#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pair<ll, ll>> pll;
#define x first
#define y first
#define x1 second.first
#define x2 second.second
#define y1 second.first
#define y2 second.second

const int MM=5e3+5, MV=15e3+5;

bool sect(pll h, pll v){
    return v.y1 <= h.y &&h.y<=v.y2&& h.x1<=v.x&&v.x<=h.x2;
}
pll h[MM],v[MM];

int bit[MV], freq[MV], fbit[MV];
void add(ll i, int v){
    for(; i < MV; i+=i&-i) bit[i]+=v;
}
ll sum(ll i){
    ll res = 0;
    for(; i > 0; i-=i&-i) res += bit[i];
    return res;
}

void update(ll x, int v){
    for(ll i = x; i < MV; i+=i&-i) fbit[i] -= freq[x]*(freq[x]-1)/2;
    freq[x]+=v;
    for(ll i = x;i<MV; i+=i&-i) fbit[i]+=freq[x]*(freq[x]-1)/2;
}
ll fsum(ll i){
    ll res = 0;
    for(;i>0;i-=i&-i)res+=fbit[i];
    return res;
}

map<int,int> compx, compy;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1, p, q, r; i <= n; i++) {
        cin >> p >> q >> r; h[i]={p,{q,r}};
        compy[p]=1;
        compx[q]=1, compx[r]=1;
    }
    for(int i = 1, p, q, r; i <= m; i++) {
        cin >> p >> q >> r; v[i]={p,{q,r}};
        compx[p]=1;
        compy[q]=1, compy[r]=1;
    }

    int idx = 1;
    for(auto[k, v] : compx){
        compx[k] = idx++;
    }
    idx=1;
    for(auto[k,v]:compy){
        compy[k] = idx++;
    }

    for(int i = 1; i <= n; i++){
        h[i].y = compy[h[i].y];
        h[i].x1 = compx[h[i].x1], h[i].x2=compx[h[i].x2];
    }
    for(int j = 1; j <= m; j++){
        v[j].x = compx[v[j].x];
        v[j].y1=compy[v[j].y1],v[j].y2=compy[v[j].y2];
    }

    ll res = 0;
    sort(h+1,h+n+1, greater<pll>());
    sort(v+1,v+m+1);
    for(int i = 1; i<=n;i++){

        vector<pii> end;
        for(pll v1 : v){
            if(sect(h[i], v1)){
                add(v1.x,1);
                end.push_back({v1.x, v1.y1});
                update(v1.x, 1);
            }
        }
        sort(end.begin(), end.end(), [](pii a, pii b){return a.second<b.second;});

        for(int j = i+1; j <= n; j++){
            pll h1=h[i], h2=h[j];
            if(h1==h2||h1.x2<=h2.x1||h2.x2<=h1.x1||h1.y==h2.y) continue;

            while(!end.empty() && end.back().second > h[j].y) {
                add(end.back().first, -1);
                update(end.back().first, -1);
                end.pop_back();
            }

            int l = max(h1.x1, h2.x1), r=min(h1.x2, h2.x2);
            ll cnt = sum(r)-sum(l-1);
            res += cnt*(cnt-1)/2 - (fsum(r) - fsum(l-1));
        }
        memset(bit,0,sizeof bit), memset(fbit,0,sizeof fbit),memset(freq,0,sizeof freq);
    }
    cout << res << "\n";

    return 0;
}