#include <bits/stdc++.h>
using namespace std;

int dp[5500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int c, n; scanf("%d%d", &c, &n);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    while(n--){
        int d; scanf("%d", &d);
        for(int i =d; i <= c; i++){
            dp[i] = min(dp[i], 1 + dp[i-d]);
        }
    }

    if(dp[c] > 10000){
        cout << "Roberta acknowledges defeat.\n";
    }else{
        cout << "Roberta wins in " << dp[c] << " strokes.";
    }

    return 0;
}