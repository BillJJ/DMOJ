#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+3;

ll a[MM], psa[MM];
ll dp[2][MM];
int p[201][MM]; // previous split point
deque<int> q;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        psa[i] += psa[i-1] + a[i];
    }

    for(int c = 1; c <= k; c++){
        q.clear();
        q.push_back(c-1);

        for(int i = c; i <= n; i++){
            dp[c&1][i] = 0;

            while(q.size() >= 2 && (dp[(c-1)&1][q[1]]-dp[(c-1)&1][q[0]]) >= (psa[n]-psa[i])*(psa[q[1]]-psa[q[0]])) q.pop_front();
            int j = q.front();
            dp[c & 1][i] = dp[(c-1)&1][j] + (ll) (psa[i] - psa[j]) * (psa[n] - psa[i]);
            p[c][i] = j;

            while(q.size() >= 2){
                int x = q[q.size()-2], y = q.back();
                if((dp[(c-1)&1][x]-dp[(c-1)&1][y])*(psa[y]-psa[i]) <= (dp[(c-1)&1][y]-dp[(c-1)&1][i])*(psa[x]-psa[y])) q.pop_back();
                else break;
            }
            q.push_back(i);
        }
    }

    int idx = 1;
    for (int i = 1; i <= n; ++i) {
        if(dp[k&1][i] > dp[k&1][idx]) idx = i;
    }

    cout << dp[k&1][idx] << "\n";

    for(int i = k; i >= 1; i--){
        cout << idx << " ";
        idx = p[i][idx];
    }

    return 0;
}