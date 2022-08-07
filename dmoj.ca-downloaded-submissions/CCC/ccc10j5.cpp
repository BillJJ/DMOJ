#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dis[9][9];
deque<pii> q;

int dirc[8][2]  = {{-2, -1}, {-2, 1}, {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;

    memset(&dis[0][0], -1, sizeof(dis));
    dis[sr][sc] = 0;
    q.push_back({sr, sc});
    while(!q.empty()){
        auto[r, c] = q.front(); q.pop_front();
        for(auto[x, y]: dirc){
            x += r, y += c;
            if(x < 1 || x > 8 || y < 1 || y > 8 || dis[x][y] != -1) continue;

            dis[x][y] = dis[r][c] + 1;
            q.push_back({x, y});
        }

    }
    cout << dis[er][ec];

    return 0;
}