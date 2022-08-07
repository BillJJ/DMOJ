#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s, t; cin >> s >> t;

    for(int i = 1; i <= s.length(); i++){
        for(int j = 1; j <= t.length(); j++){
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    pair<int, int> p = {s.length(), t.length()};
    string ret = "";
    while(dp[p.first][p.second] != 0){
        if(dp[p.first][p.second] == dp[p.first - 1][p.second]) p.first--;
        else if(dp[p.first][p.second] == dp[p.first][p.second - 1]) p.second--;
        else {
            ret += s[p.first-1];
            p.first--, p.second--;
        }
    }
    reverse(ret.begin(), ret.end());
    cout << ret;

    return 0;
}