#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

const int MM = 100+5;

deque<pdi> q[MM];
bool vis[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    priority_queue<pdi> pq;
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int idx; double know; cin >> idx >> know;
            pq.push({know, idx});
        }
    }
    double res = 0;
    while(k--){
        while(vis[pq.top().second]) pq.pop();
        res += pq.top().first;
        vis[pq.top().second] = 1;
        pq.pop();
    }
    printf("%.1f", res);

    return 0;
}