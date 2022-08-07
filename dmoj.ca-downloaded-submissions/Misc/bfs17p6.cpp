#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5, MV = 5e3+5;

struct block{
    int l, w, h, i; ll p;
} a[MM];

ll bit[MV][MV];
int pa[MM];

void add(int x, int y, int idx){
    for(int i = x; i <= MV; i+=i&-i){
        for(int j = y; j <= MV; j+=j&-j){
            if(a[idx].p > a[bit[i][j]].p){
                bit[i][j] = idx;
            }
        }
    }
}

ll query(int x, int y){
    ll res = 0;
    for(int i = x; i > 0; i-=i&-i){
        for(int j = y; j > 0; j -=j&-j){
            if(a[res].p < a[bit[i][j]].p){
                res = bit[i][j];
            }
        }
    }
    return res;
}

vector<int> out;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].w >> a[i].h >> a[i].p;
        a[i].i = i;
        if(a[i].w > a[i].l) swap(a[i].l, a[i].w);
    }

    sort(a+1, a+n+1, [](block x, block y){return x.h < y.h || x.h==y.h&&x.l<y.l|| x.h==y.h&&x.l==y.l&&x.w<y.w;});

    for(int i = 1; i <= n; i++){
        pa[i] = query(a[i].l, a[i].w);
        a[i].p += a[pa[i]].p;
        add(a[i].l, a[i].w, i);
    }

    int best = query(5000, 5000);
    cout << a[best].p << "\n";
    while(best > 0){
        out.push_back(best);
        best = pa[best];
    }
    cout << out.size() << "\n";
    for(int &i : out){
        cout << a[i].i <<" ";
    }
    return 0;
}