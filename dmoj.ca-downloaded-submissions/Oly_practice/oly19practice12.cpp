#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e4+5;

ll a[MM];
ll dp[2][MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int c = 1; c <= k; c++){

        ll best = c-1;

        for(int i = 1; i < c; i++) dp[c&1][i] = dp[c&1][i-1] + a[i];

        for(int i = c; i <= n; i++){
            dp[c&1][i] = dp[c&1][i-1] + a[i];
            dp[c&1][i] = max(dp[c&1][i], dp[(c-1)&1][best] + a[i]);

            if(dp[(c-1)&1][i] > dp[(c-1)&1][best]) best = i;
        }
    }

    ll res = LLONG_MIN;
    for (int i = k; i <= n; ++i) {
        res = max(res, dp[k&1][i]);
    }
    cout << res;

    return 0;
}