#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e3+5, mod=1e9+7;

int a[10], n;
string s;

ll dp[MM][1<<10][2][2];
ll f(int pos, int mask, bool bound, bool nzp){ // non-zero-prefix
    if(dp[pos][mask][bound][nzp] != -1) return dp[pos][mask][bound][nzp];

    if(pos == n){
        bool flag = 1;
        for(int i = 0; i <= 9; i++){
            if(a[i]){
                flag &= (mask & (1<<i))>0;
            }
        }
        return dp[pos][mask][bound][nzp] = flag;
    }

    int r = (bound? s[pos]-'0' : 9);
    ll res = 0;
    for(int i = 0; i <= r; i++){
        if(i == 0 && !nzp)
            res += f(pos+1, mask, bound&&i==s[pos]-'0', 0);
        else
            res += f(pos+1, mask|(1<<i), bound && i==s[pos]-'0', nzp || i!=0);
        res %= mod;
    }
    return dp[pos][mask][bound][nzp] = res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dp, -1, sizeof dp);

    int digs; cin >> digs;
    for (int i = 1; i <= digs; ++i) {
        int x; cin>> x;
        a[x] = 1;
    }
    cin >> s;
    n = s.size();

    if(digs == 1 && a[0]) {cout << f(0, 0, 1, 0) + 1; return 0;}

    cout << f(0, 0, 1, 0);


    return 0;
}