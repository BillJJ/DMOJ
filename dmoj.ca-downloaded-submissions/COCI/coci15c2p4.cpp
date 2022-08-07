#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e5+5;

const ll mod = 1125899906842679, prime = 101;

map<ll, int> dp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    int res = 0;
    while(n--){
        string s; cin >> s;
        ll prefix = 0, suffix = 0, pw = 1;
        int best = 0;
        for(int i = 0; i < s.size(); i++){
            prefix = (prefix * prime + s[i]) % mod;
            suffix = (suffix + s[s.size()-1-i] * pw) % mod;

            if(prefix == suffix && dp[prefix]){
                best = max(best, dp[prefix]);
            }
            pw = (prime * pw) % mod;
        }
        dp[prefix] = best + 1;
        res = max(res, dp[prefix]);
    }
    cout << res;
    return 0;
}