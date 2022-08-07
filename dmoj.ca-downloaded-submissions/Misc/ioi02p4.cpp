#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e4+5;

int dp[MM], f[MM], t[MM];
deque<int> q;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, s; cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> f[i];
    }

    for(int i = n; i >= 1; i--) f[i] += f[i+1], t[i] += t[i+1];

    memset(dp, 0x3f, sizeof dp);
    dp[n+1] = 0;
    q.push_back(n+1);

    for(int i = n; i >= 1; i--){

        while(q.size() >= 2){
            int k = q.front(); q.pop_front();
            int j = q.front(); q.pop_front();
            if(dp[j] - dp[k] <= f[i]*(t[j] - t[k])){
                q.push_front(j);
                continue;
            } else{
                q.push_front(j);
                q.push_front(k);
                break;
            }
        }
        int j = q.front();
        dp[i] = dp[j] + (s+t[i]-t[j])*f[i];

        while(q.size() >= 2){
            int a = q.back(); q.pop_back();
            int b = q.back(); q.pop_back();
            if((dp[a] - dp[b])*(t[i]-t[a]) > (dp[i]-dp[a]) * (t[a]-t[b])){
                q.push_back(b);
                continue;
            } else{
                q.push_back(b);
                q.push_back(a);
                break;
            }
        }
        q.push_back(i);
    }

    cout << dp[1];

    return 0;
}