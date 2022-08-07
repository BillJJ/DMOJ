#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5, inf=MM*50;

struct cor{
    int x, y, d, w;
};

vector<vector<char>> grid;

vector<int> dis[4][MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    grid.resize(n+5);
    for (int i = 1; i <= n; ++i) {
        grid[i].resize(m+5);

        for(int j = 0 ; j < 4; ++j) {
            dis[j][i].resize(m+5);
            fill(dis[j][i].begin(), dis[j][i].end(), inf);
        }

        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    dis[3][1][1] = 0;

    int dircl[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dircr[4][2] = {{-1, 0},{0, -1}, {1, 0}, {0, 1}};
    int leftcon[] = {3, 2, 1, 0}, rightcon[] = {1, 0, 3, 2};

    deque<cor> q;
    q.push_back({1, 1, 3, 0});
    while(!q.empty()){
        auto[x, y, d, w] = q.front(); q.pop_front();
        bool left = !(grid[x][y] == '/'), right = !(grid[x][y] == '\\');
        auto[i, j] = dircl[d];
        if(x+i >= 1 && x+i <= n && y+j >= 1 && y+j <= m && left + w < dis[leftcon[d]][x+i][y+j]){
            dis[leftcon[d]][x+i][y+j] = left+w;
            if(left){
                q.push_back({x+i, y+j, leftcon[d], left+w});
            } else{
                q.push_front({x+i, y+j, leftcon[d], left+w});
            }
        }

        i = dircr[d][0], j=dircr[d][1];
        if(x+i >= 1 && x+i <= n && y+j >= 1 && y+j <= m && right + w < dis[rightcon[d]][x+i][y+j]){
            dis[rightcon[d]][x+i][y+j] = right+w;
            if(right){
                q.push_back({x+i, y+j, rightcon[d], right+w});
            } else{
                q.push_front({x+i, y+j, rightcon[d], right+w});
            }
        }
    }

    if(dis[2][n][m] + !(grid[n][m]=='\\') >= inf){
        cout << "-1";
    } else{
        cout << dis[2][n][m] + !(grid[n][m]=='\\');
    }

    return 0;
}