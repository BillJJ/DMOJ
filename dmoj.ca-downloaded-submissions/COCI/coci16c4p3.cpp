#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 505;

int a[MM], dp[505][100005];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n; int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; sum += a[i];
    }

    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j+a[i]] = max({dp[i][j+a[i]], dp[i-1][j+a[i]], dp[i-1][j]+a[i]});
            dp[i][abs(j-a[i])] = max({dp[i][abs(j-a[i])], dp[i-1][abs(j-a[i])], dp[i-1][j]+a[i]});
        }
    }

    cout << sum-dp[n][0]/2;

    return 0;
}