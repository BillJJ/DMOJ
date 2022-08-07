#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e5+5;
int n, a[MM], dp[MM];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[1] = a[1];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+a[i]);
    }
    cout << dp[n];

    return 0;
}