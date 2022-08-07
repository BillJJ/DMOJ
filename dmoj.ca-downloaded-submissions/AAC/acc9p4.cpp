#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

string s; ll n, k, ans;
int dp[11][20][20][1<<10]; // (k, s.size(), pos, mask): -1 unexplored, 0 doesn't work, 1 = work
bool f(int pos, int mask, int lower, ll num){
//    if(k == 5 && pos == 5 && mask == 456){
//        cout << "jksdnf" << "\n";
//    }
    if(dp[k][s.size()][pos][mask]==0 && !lower) return 0;

    int d = 0;
    for(int i = 0; i <= 9; i++){
        if(mask&1<<i) d++;
    }

    if(pos == s.size()){
        if(d == k) {
            ans = num;
            if(!lower) dp[k][s.size()][pos][mask] = 1;
            return 1;
        }
        if(!lower) dp[k][s.size()][pos][mask] = 0;
        return 0;
    }
    bool res = 0;
    for(int i = lower?s[pos]-'0':0; i <= 9 && !res; i++){
        if(d == k){
            if(mask&1<<i)
                res |= f(pos+1, mask|1<<i, lower&&i==s[pos]-'0', num*10+i);
        } else{
            res |= f(pos+1, mask|1<<i, lower&&i==s[pos]-'0', num*10+i);
        }
    }
    if(!lower) dp[k][s.size()][pos][mask] = res;
    return res;
}

void solve(){
    cin >> n >> k;
    ans = LLONG_MAX;
    s = to_string(n);
    if(k <= s.size()){
        if(f(0, 0, 1, 0)) {
            cout << ans << "\n";
            return;
        }
    }

    const string good = "1023456789";
    string res = good.substr(0, k);
    while(res.size() <= s.size()) res.insert(1, "0");

    cout << res << "\n";

    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dp, -1, sizeof dp);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}