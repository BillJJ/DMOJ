#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MM = 1e6+5, mod=1e9+7;

int a[MM];

signed main(){
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll res = 0;

    ll p = 1;
    for(int i = 1; i <= n-1; i++){
        p = (p*2)%mod;
    }

    for(int i = 1; i <= n; i++){
        res += p*a[i]%mod;
        res %= mod;
    }

    cout << res;
        
    return 0;
}