#include <bits/stdc++.h>
using namespace std;
#define ll long long

int v[101], w[101];
ll dp[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, c; cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = c; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout << dp[c];

    return 0;
}