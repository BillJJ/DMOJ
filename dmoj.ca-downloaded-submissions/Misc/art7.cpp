#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5, mod=1e9+7;
string s;

ll dp[100005][2][2][4];
ll f(int pos, bool bound, bool one, int zero){ // only count zeros after first one
    if(zero >= 2) zero = 2;

    if(dp[pos][bound][one][zero] != -1 ) return dp[pos][bound][one][zero];

    if(pos == s.size()){
        if(one && zero == 1) return 1;
        else return 0;
    }
    int r = bound?s[pos]-'0':9;
    ll res = 0;
    for(int i = 0; i <= r; i++){
        if(!one && i == 1){
            res += f(pos+1, bound&&(i==s[pos]-'0'), 1, 0);
        } else if(one && i == 0){
            res += f(pos+1, bound&&(i==s[pos]-'0'), 1, zero+1);
        } else
            res += f(pos+1, bound&&(i==s[pos]-'0'), one, zero);
        res %= mod;
    }
    return dp[pos][bound][one][zero] = res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << f(0, 1, 0, 0);

    return 0;
}