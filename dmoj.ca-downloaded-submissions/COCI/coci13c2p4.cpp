#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1.5e3+5, mod=1e9+7;

int dp[MM][MM]; // first : last : dis

int a[MM][MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[1][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][i - 1]);
            dp[j][i] = min(dp[j][i], dp[j][i - 1] + a[i][i - 1]);
        }

        for(int k = 1; k < i-1; k++) {
            dp[i][i-1] = min(dp[i][i-1], dp[k][i-1] + a[i][k]);
            dp[i-1][i] = min(dp[i-1][i], dp[i-1][k] + a[i][k]);
        }
    }

    int res = INT_MAX;
    for(int i = 1; i < n; i++){
        res = min({res, dp[i][n], dp[n][i]});
    }
    cout << res;

    return 0;
}