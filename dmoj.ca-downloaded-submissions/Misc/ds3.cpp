#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 100005;
struct bot{
    int a, m, g, e;
};

bot t[2*MM];
int n;

void build(){
    // configure all the leafs
    for(int i = n*2-1; i >= n; i--){
        t[i].g = t[i].a;
        t[i].e = 1;
        t[i].m = t[i].a;
    }
    for(int i = n-1; i; i--){
        t[i].m = min(t[i*2].m, t[i*2+1].m);
        t[i].g = gcd(t[i*2].g, t[i*2+1].g);

        if(t[i].g == t[i*2].g){
            t[i].e += t[i*2].e;
        }
        if(t[i].g == t[i*2+1].g){
            t[i].e += t[i*2+1].e;
        }
    }
}

void modify(int p, int v){
    p+= n;
    t[p].a = v;
    t[p].m = v;
    t[p].g = v;
    for(; p > 1; p/= 2){
        t[p/2].m = min(t[p].m, t[p^1].m);
        t[p/2].g = gcd(t[p].g, t[p^1].g);
        t[p/2].e = 0;
        if(t[p/2].g == t[p].g) t[p/2].e += t[p].e;
        if(t[p/2].g == t[p^1].g) t[p/2].e += t[p^1].e;
    }
}

// all queries are [l, r)
int query_min(int l, int r){
    int res = INT_MAX;
    for(l += n, r+=n; l<r; l/=2, r/=2){
        if(l&1) res = min(res, t[l++].m);
        if(r&1) res = min(res, t[--r].m);
    }
    return res;
}

int query_gcd(int l, int r){
    int res = t[l+n].g;
    for(l+=n, r+=n; l < r; l/=2, r/=2 ){
        if(l&1) res = gcd(res, t[l++].g);
        if(r&1) res = gcd(res, t[--r].g);
    }
    return res;
}

int query_q(int l, int r){
    int v = query_gcd(l, r);
    int res = 0;
    for(l += n, r+= n; l < r; l/=2, r/=2){
        if(l&1){
            if(t[l].g == v) res += t[l].e;
            l++;
        }
        if(r&1){
            r--;
            if(t[r].g == v) res += t[r].e;
        }
    }
    return res;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> t[i+n].a;
    }

    build();
    while(m--){
        char cmd; int x, y;
        cin >> cmd >> x >> y;
        if(cmd == 'C'){
            modify(x-1, y);
        }
        else if(cmd == 'M'){
            cout << query_min(x-1, y) << '\n';
        }
        else if(cmd == 'G'){
            cout << query_gcd(x-1, y) << '\n';
        }
        else{
            cout << query_q(x-1, y) << '\n';
        }
    }

    return 0;
}