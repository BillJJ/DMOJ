#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 3e5+5;

vector<int> backedge[MM];
int dp[MM]; // the highest node reachable by i
bool vis[MM];

int dfs(int x){
    if(dp[x]) return dp[x];
    vis[x] = 1;
    for(int e : backedge[x]){
        if(vis[e]) continue;
        dp[x] = max({dp[x], e, dfs(e)});
    }
    return dp[x];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;
    bool goes_up = 0;
    while(m--){
        int a, b; cin >> a >> b;
        backedge[b].push_back(a);
        if(a < b){
            goes_up = 1;
        }
    }

    if(!goes_up){
        cout << -1; return 0;
    }

    for(int i = n; i >= 1; i--){
        dfs(i);
    }

    int x = 0, y = 0;
    for(int i = n; i >= 1; i--){
        if(dp[i] > x){
            x = dp[i];
            y = i;
        }
    }

    cout << x << ' ' << y;

    return 0;
}