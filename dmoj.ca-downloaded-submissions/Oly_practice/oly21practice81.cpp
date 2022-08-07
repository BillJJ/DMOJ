#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e3+5;

pii s, e;
char grid[MM][MM];
int dis[MM][MM];
deque<pii> q;

int dirc1[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dirc2[][2] = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    cin >> s.first >> s.second >> e.first >> e.second;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++ ) cin >> grid[i][j];

    q.push_back(s);
    while(!q.empty()){
        auto[x, y] = q.front(); q.pop_front();

        for(auto[i, j] : dirc1){
            if(dis[x+i][y+j] || x+i < 1 || x+i > n || y+j < 1 || y+j > m || grid[x+i][y+j] == '#') continue;
            dis[x+i][y+j] = dis[x][y]+1;
            q.push_back({x+i, y+j});
        }
        for(auto[i, j] : dirc2){
            if(dis[x+i][y+j] || x+i < 1 || x+i > n || y+j < 1 || y+j > m || grid[x+i][y+j] == '#') continue;
            dis[x+i][y+j] = dis[x][y]+1;
            q.push_back({x+i, y+j});
        }
    }

    cout << (dis[e.first][e.second] == 0 ? -1 : dis[e.first][e.second]);

    return 0;
}