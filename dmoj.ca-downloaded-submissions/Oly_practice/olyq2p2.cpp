#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T; ll L, R, dp[20][1<<8][2525];  string s;
ll f(int pos, bool bound, int mask, int sum){
    if(pos == -1){
        bool flag = 1;
        for(int i = 2; i <= 9; i++){
            if(mask&(1<<i-2)){
                flag &= (sum%i==0);
            }
        }
        return flag;
    }

    if(!bound && dp[pos][mask][sum] != -1) return dp[pos][mask][sum];

    int r = bound?s[pos]-'0':9;
    ll res = 0;
    for(int i = 0; i <= r; i++){
        if(i <= 1)
            res += f(pos-1, bound&&i==s[pos]-'0', mask, (sum*10 + i)%2520);
        else
            res += f(pos-1, bound&&i==s[pos]-'0', mask|(1<<i-2), (sum*10 + i)%2520);
    }
    if(!bound)dp[pos][mask][sum] = res;
    return res;
}

ll solve(ll x){
    s = to_string(x);  reverse(s.begin(), s.end());
    return f((int)s.size()-1, 1, 0, 0);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    for(cin >> T; T--; ){
        cin >> L >> R;
        cout << solve(R) - solve(L-1) << "\n";
    }
}