#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[4][10005];
int v[3], w[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, c; cin >> n >> c;

    for(int i = 1; i <= n; i++){

        for(int j = 0; j < 3; j++) cin >> w[j] >> v[j];

        for(int j = c; j >= w[0]; j--){
            dp[0][j] = max(dp[3][j], dp[3][j-w[0]] + v[0]);
        }
        for(int j = c; j >= w[1]; j--){
            dp[1][j] = max(dp[3][j], dp[3][j-w[1]] + v[1]);
        }
        for(int j = c; j >= w[2]; j--){
            dp[2][j] = max(dp[3][j], dp[3][j-w[2]] + v[2]);
        }
        for(int j = 0; j <= c; j++){
            dp[3][j] = max({dp[0][j], dp[1][j], dp[2][j]});
        }
    }

    cout << dp[3][c];

    return 0;
}