#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e3+5;

bool a[MM][MM];
ll dp[MM][MM], u[MM], d[MM];

vector<int> col[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c; cin >>c;
            a[i][j] = c-'0';
            if(a[i][j]) col[j].push_back(i);
        }
    }

    memset(dp, 0x3f, sizeof dp);
    for(int i =1;i<=n;i++)dp[i][1]=0;
    for(int j = 2; j <= m; j++){
        memset(u, 0x3f, sizeof u);
        memset(d, 0x3f, sizeof d);

        int last = 0;
        for(int i : col[j]){
            for(int k = last; k < col[j-1].size() && col[j-1][k] <= i; k++){
                int x = col[j-1][k];
                ll v = dp[x][j-1]+1LL*(x-i)*(x-i);
                if(v <= u[i]){
                    u[i] = v;
                    last = k;
                }
            }
        }
        last = col[j-1].size()-1;
        for(int shit = col[j].size()-1; shit >= 0; shit--){
            int i = col[j][shit];

            for(int k = last; k >= 0 && col[j-1][k] > i; k--){
                int x = col[j-1][k];
                ll v = dp[x][j-1]+1LL*(x-i)*(x-i);
                if(v <= d[i]){
                    d[i] = v;
                    last = k;
                }
            }
            dp[i][j] = min(u[i], d[i]);
        }
    }

    ll res = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        res = min(res, dp[i][m]);
    }
    cout << res;

    return 0;
}