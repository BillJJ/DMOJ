#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

ll x[MM], dp[MM], p[MM], a,b, c;

double w(int k, int j){
    return (double)(dp[j]-dp[k] + a*(p[j]*p[j] - p[k]*p[k]) + b*(p[k]-p[j])) / (p[j]-p[k]);
}
deque<int> q;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        p[i] += p[i-1] + x[i];
    }
    memset(dp, -0x3f, sizeof dp);
    dp[0]=0;
    q.push_back(0);
    for(int i = 1; i <= n; i++){
        while(q.size() >= 2 && w(q[0], q[1]) >= 2*a*p[i]) q.pop_front();
        int j = q.front();
        ll xt = p[i]-p[j];
        dp[i] = dp[j]+a*xt*xt + b*xt + c;
        while (q.size() >= 2 && w(q[q.size()-2], q.back()) <= w(q.back(), i)) q.pop_back();
        q.push_back(i);
    }

    cout << dp[n];
    return 0;
}