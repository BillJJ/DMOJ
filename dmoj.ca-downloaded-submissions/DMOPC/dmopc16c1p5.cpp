#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 5e5+5, MV=2e6;
#define int ll
int bit[MM];
void add(int i){
    for(;i<MM;i+=i&-i) bit[i]++;
}

int query(int i){
    int res = 0;
    for(;i>0;i-=i&-i) res += bit[i];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        int beg=query(x-1), end=query(n)-query(x);
        if(beg > end){
            res += end;
        } else{
            res += beg;
        }
        add(x);
    }

    cout << res;

    return 0;
}