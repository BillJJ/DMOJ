#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100001];
int dp[100001];

int dfs(int x){
    if(dp[x]) return dp[x];

    int ret = 0;
    for(int e : edge[x]){
        ret = max(ret, 1 + dfs(e));
    }
    dp[x] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
    }
    int ret = 0;
    for(int i = 1; i <= n; i++){
        ret = max(ret, dfs(i));
    }

     cout << ret;

    return 0;
}