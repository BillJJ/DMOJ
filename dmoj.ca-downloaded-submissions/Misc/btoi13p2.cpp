#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

string s;
ll dp[20][2][2][11][11];
ll f(int pos, bool bound, bool nzp, int pp, int p){// previous num and second previous num
    if(dp[pos][bound][nzp][pp][p] != -1) return dp[pos][bound][nzp][pp][p];

    if(pos == s.size()){
        return dp[pos][bound][nzp][pp][p] = 1;
    }

    int r = bound?s[pos]-'0' : 9;
    ll res = 0;
    for(int i = 0; i <= r; i++){
        if(!nzp && i == 0){
            res += f(pos+1, bound&&i==s[pos]-'0', 0, 10, 10);
        } else{
            if(i == p || i == pp) continue;
            res += f(pos+1, bound&&i==s[pos]-'0', 1, p, i);
        }
    }
    return dp[pos][bound][nzp][pp][p] = res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dp, -1, sizeof dp);
    ll a, b; cin >> a >> b;
    s = to_string(b);
    ll ans = f(0, 1, 0, 10, 10);

    memset(dp, -1, sizeof dp);
    s = to_string(a-1);
    ll ans2 = f(0, 1, 0, 10, 10);
    cout << ans - ans2;

    return 0;
}