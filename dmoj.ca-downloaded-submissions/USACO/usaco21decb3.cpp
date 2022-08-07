#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

bool blocked[55][55];
int n;

int dfs(int x, int y, int k, int dirc){ // dirc 1 for right, 2 for down
    if(x == n && y == n) return 1;
    int res = 0;
    if(dirc == 1){
        if(x+1 <= n && !blocked[x+1][y]) res += dfs(x+1, y, k, 1);
        if(y+1 <= n && k && !blocked[x][y+1]) res += dfs(x, y+1, k-1, 2);
    } else{
        if(x+1 <= n && k && !blocked[x+1][y]) res += dfs(x+1, y, k-1, 1);
        if(y+1 <= n && !blocked[x][y+1]) res += dfs(x, y+1, k, 2);
    }
    return res;
}

void solve(){
    int k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            if(c == '.') blocked[i][j] = 0;
            else blocked[i][j] = 1;
        }
    }
    int res = 0;
    if(!blocked[2][1]) res+=dfs(2, 1, k, 1);
    if(!blocked[1][2]) res+=dfs(1, 2, k, 2);
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}