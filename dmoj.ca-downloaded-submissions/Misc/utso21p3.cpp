#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5, mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, x; cin >> n;
    cin >> x;
    int mx = x, stk = 0; ll res = 1;
    for(int i = 2; i <= n; i++) {
        cin >> x;
        if(x >= mx && stk == 0){
            res = (res*2)%mod;
        } else if(x >= mx && stk > 0){
            res = (res * (stk+2)) % mod;
            stk = 0;
        } else{
            stk++;
        }
        mx = max(mx, x);
    }

    cout << res;

    return 0;
}