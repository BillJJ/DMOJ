#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5, mod=1e9+7;
ll a[MM],b[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    ll res = 0;

    if(a[n] > b[n]) swap(a[n], b[n]);

    if(k <= b[n]-a[n]) a[n] += k;
    else{
        k -= b[n]-a[n];
        a[n] = b[n];
        a[n] += k/2;
        b[n] += k/2;
        if(k&1) a[n]++;

        a[n]%=mod, b[n]%=mod;
    }

    for(int i =1; i <= n; i++){
        res = (res + a[i]%mod*b[i]%mod)%mod;
    }

    cout << res << "\n";

    return 0;
}