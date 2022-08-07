#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 1e3+5;

vector<int> edge[MM];
int vis[5][MM];
int ans[MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 4; j++){
            if(!vis[j][i]) {
                ans[i] = j;
                vis[j][i] = 1;
                for(int v : edge[i]){
                    vis[j][v] = 1;
                }
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i];
    }

    return 0;
}