#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int x, n; scanf("%d%d", &x, &n);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    while(n--){
        int d; scanf("%d", &d);
        for(int i = d; i <= x; i++){
            dp[i] = min(dp[i], 1 + dp[i-d]);
        }
    }
    printf("%d", dp[x]);
    return 0;
}