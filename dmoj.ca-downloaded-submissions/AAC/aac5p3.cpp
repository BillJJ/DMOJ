#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=2e5+5, mod=1e9+7;

vector<pii> edge[MM]; // difficulty : v

int ans[MM], s[MM], n, k;

void dfs(int u, int l, int r){
    if(r > k) return;

    ans[u] = r-l+1;

    if(edge[u].size() == 1){
        dfs(edge[u][0].second, l, r);
    } else if(edge[u].size() == 2){

        int split = (edge[u][0].first + edge[u][1].first)/2; // s[i] <= split go down else up

        int upidx = upper_bound(s+l, s+r+1, split)-s;
        dfs(edge[u][0].second, l, upidx-1);
        dfs(edge[u][1].second, upidx, r);
    } else if(edge[u].size() >= 3){
        edge[u].push_back({INT_MAX, -1});
        for(int i = 0; i+1 < edge[u].size(); i++){

            int splithigh = ((ll)edge[u][i].first + (ll)edge[u][i+1].first)/2; // s[i] <= splithigh goes to v
            int splitlow, left, right;
            if(i == 0) splitlow = 0, left = l;
            else {
                splitlow = (edge[u][i-1].first + edge[u][i].first)/2; // splitlow < s[i] goes to v
                left = upper_bound(s+l, s+r+1, splitlow)-s;
            }
            right = upper_bound(s+l, s+r+1, splithigh)-s;
            dfs(edge[u][i].second, left, right-1);
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1, a, b, d; i < n; i++){
        cin >> a >> b >> d;
        edge[a].push_back({d, b});
    }

    for(int i = 1; i <= k; i++) cin >> s[i];
    sort(s+1, s+k+1);

    for(int i = 1; i <= n; i++){
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(1, 1, k);

    cout << ans[1];
    for(int i = 2; i <= n; i++) cout << " " << ans[i];
    cout << "\n";

    return 0;
}