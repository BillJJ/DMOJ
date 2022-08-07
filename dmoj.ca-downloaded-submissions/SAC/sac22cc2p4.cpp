#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int MM = 1e6+5;

int dirc[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
deque<pip> q;
char grid[1005][1005];
bool vis[1005][1005];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    if (grid[1][1] == '.') q.push_back({0, {1, 1}});
    else q.push_back({1, {1, 1}});
    while(!q.empty()){
        pip cur = q.front(); q.pop_front();
        int dis = cur.first;
        auto[x, y] = cur.second;
        if(vis[x][y]) continue;

        vis[x][y] = 1;
        if(x == n && y == m){
            cout << dis; return 0;
        }

        for(auto[i, j] : dirc){
            if(x+i > 0 && x+i <= n && y+j > 0 && y+j <= m && !vis[x+i][y+j]){
                if(grid[x+i][y+j] == '.') q.push_front({dis, {x+i, y+j}});
                else q.push_back({dis+1, {x+i, y+j}});
            }
        }
    }

    return 0;
}