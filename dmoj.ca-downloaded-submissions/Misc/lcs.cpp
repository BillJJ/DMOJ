#include <bits/stdc++.h>
using namespace std;

const int MM = 1005;

int dp[MM][MM];
int s[MM], t[MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int lens, lent; cin >> lens >> lent;

    for(int i = 0; i < lens; i++) cin >> s[i];
    for(int i = 0; i < lent; i++) cin >> t[i];

    for(int i = 1; i <= lens; i++){
        for(int j = 1; j <= lent; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[lens][lent];

    return 0;
}