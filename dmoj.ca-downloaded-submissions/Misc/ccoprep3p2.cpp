#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e6+5;

ll a[MM], dp[MM], p[MM];
ll n, l;

double w(int k, int j){
    return (double)(dp[k]-dp[j]+k*k-j*j+p[k]*p[k]-p[j]*p[j]+2*((l+1)*(p[k]-p[j]) + k*p[k] - j*p[j] +(l+1)*(k-j)))/(p[j] - p[k] + j - k);
}
ll f(int j, int i){
    return dp[j] + ((i - j - 1) + p[i]-p[j] - l)*((i - j - 1) + p[i]-p[j] - l);
}
deque<int> q;
ll ans(){
    memset(dp, 0x3f, sizeof dp);
    q.push_back(0);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        while(q.size() >= 2 && f(q[0], i) >= f(q[1], i))
            q.pop_front();

        int j = q[0];
        dp[i] = dp[j] + ((i - j - 1) + p[i]-p[j] - l)*((i - j - 1) + p[i]-p[j] - l);

        while(q.size() >= 2 && w(q[q.size()-2], q.back()) <= w(q.back(), i)) q.pop_back();
        q.push_back(i);
    }
    return dp[n];
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i-1]+a[i];
    }

    milliseconds start = duration_cast< milliseconds >(
            system_clock::now().time_since_epoch()
    );

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int last = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = last; j < i; ++j) {
            ll v = dp[j] + ((i - j - 1) + p[i]-p[j] - l)*((i - j - 1) + p[i]-p[j] - l);
            if(dp[i] > v){
                dp[i] = v;
                last = j;
            }
        }
        milliseconds t = duration_cast< milliseconds >(
                system_clock::now().time_since_epoch()
        );
        if(t.count() - start.count() > 800){
            cout << ans();
            return 0;
        }
    }
    cout << dp[n];
    return 0;
}