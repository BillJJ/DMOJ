#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

string s;
int digsum;

ll dp[19][170][2];
ll f(int pos, int sum, bool bound){
    if(dp[pos][sum][bound] != -1) return dp[pos][sum][bound];

    if(pos == s.size())
        return dp[pos][sum][bound] = (sum == digsum);

    int hi = (bound?s[pos]-'0' : 9);
    ll res = 0;
    for(int i = 0; i <= hi; i++){
        res += f(pos+1, sum+i, i == s[pos]-'0' && bound);
    }
    return dp[pos][sum][bound] = res;
}

ll solve(ll top, int sum){
    memset(dp, -1, sizeof dp);
    digsum = sum;
    s = to_string(top);
    return f(0, 0, 1);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll l, r; cin >> l >> r;
    s = to_string(r);
    int res = 0;
    for(int i =1; i <= 9*18; i++){
        if(solve(r, i) - solve(l-1, i) > 0) res++;
    }
    cout << res;

    return 0;
}