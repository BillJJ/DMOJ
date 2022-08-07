#include <bits/stdc++.h>
using namespace std;

int a[1505][1505];
int dp[1505][1505];
int dirc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs(int i, int j){
    if(dp[i][j]) return dp[i][j];

    int ret = 0;
    for(auto [x, y] : dirc){
        if(a[i+x][j+y] > a[i][j]){
            ret = max(ret, 1 + dfs(i+x, j+y));
        }
    }
    dp[i][j] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n;j ++){
            cin >> a[i][j];
        }
    }
    int best = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n;j ++){
            best = max(best, dfs(i, j));
        }
    }

    cout << best;

    return 0;
}