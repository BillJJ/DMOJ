#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

ll a[MM], dp[MM];
deque<int> q;

double slope(int x, int y){ // x < y
    return (double)(dp[y]-dp[x] + a[y]*a[y] - a[x]*a[x])/(a[y]-a[x]);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, c; cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0;
    q.push_back(1);
    for (int i = 2; i <= n; ++i) {
        while(q.size() >= 2 && dp[q[0]]+(a[i]-a[q[0]])*(a[i]-a[q[0]]) >= dp[q[1]]+(a[i]-a[q[1]])*(a[i]-a[q[1]])) q.pop_front();
        int j = q.front();
        dp[i] = dp[j] + c + (a[i]-a[j])*(a[i]-a[j]);

        while(q.size() >= 2 && (dp[q.back()] - dp[q[q.size()-2]] + a[q.back()]*a[q.back()] - a[q[q.size()-2]]*a[q[q.size()-2]]) * (a[i] - a[q.back()]) >
                               (dp[i]-dp[q.back()]+a[i]*a[i] - a[q.back()]*a[q.back()]) * (a[q.back()] - a[q[q.size()-2]])) q.pop_back();
        q.push_back(i);
    }

    cout << dp[n];

    return 0;
}