#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e2+5;

int n, m;
char grid[MM][MM];

bool cam[MM][MM];
void cam_colour(int x, int y){
    for(int i = x; i <= n; i++){
        if(grid[i][y] == 'W') break;
        else if(grid[i][y] == '.') cam[i][y] = 1;
    }
    for(int i = x; i >= 1; i--){
        if(grid[i][y] == 'W') break;
        else if(grid[i][y] == '.') cam[i][y] = 1;
    }
    for(int j = y; j <= m; j++){
        if(grid[x][j] == 'W') break;
        else if(grid[x][j] == '.') cam[x][j] = 1;
    }
    for(int j = y; j >= 1; j--){
        if(grid[x][j] == 'W') break;
        else if(grid[x][j] == '.') cam[x][j] = 1;
    }
}

pii con_end[MM][MM]; // points to end of conveyer
bool con_vis[MM][MM];
pii conveyer_colour(int x, int y){ // return ends of conveyer, if infinite return {-1, -1}
    if(grid[x][y] == '.' && !cam[x][y]) {return {x,y};}

    if(con_end[x][y].first == -1 || grid[x][y] == 'W' || cam[x][y]) return {-1, -1};
    else if(con_end[x][y].first != 0) return con_end[x][y];

    if(con_vis[x][y]) return {-1, -1};

    con_vis[x][y] = 1;

    switch(grid[x][y]){
        case 'L': con_end[x][y] = conveyer_colour(x,y-1); break;
        case 'R': con_end[x][y] = conveyer_colour(x,y+1); break;
        case 'U': con_end[x][y] = conveyer_colour(x-1,y); break;
        case 'D': con_end[x][y] = conveyer_colour(x+1,y); break;
    }
    return con_end[x][y];
}

pii s;
int dis[MM][MM];
deque<pii> q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n;i ++)
        for(int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') {
                s.first = i, s.second = j;
                grid[i][j] = '.';
            }
        }

    for(int i = 1; i <= n; i++){
        for(int j= 1; j <= m; j++){
            if(grid[i][j] == 'C') cam_colour(i, j);
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(grid[i][j] != 'W' && grid[i][j] != '.' && grid[i][j] != 'C') conveyer_colour(i, j);
        }

    memset(dis, -1, sizeof dis);

    if(cam[s.first][s.second]){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if((pii){i,j}==s) continue;
                if(grid[i][j] == '.'){
                    cout << dis[i][j] << "\n";
                }
            }
        }
        return 0;
    }

    q.push_back(s);
    dis[s.first][s.second] = 0;
    int dirc[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        auto[x, y] = q.front(); q.pop_front();
        for(auto[i, j] : dirc){
            if(grid[i+x][j+y] != 'W' && !cam[i+x][j+y] && dis[i+x][j+y] == -1){
                if(grid[i+x][j+y] == '.'){
                    dis[i+x][j+y] = dis[x][y]+1;
                    q.push_back({i+x, j+y});
                }else if(con_end[x+i][y+j].first >= 1 && dis[con_end[x+i][y+j].first][con_end[x+i][y+j].second] == -1){
                    dis[con_end[x+i][y+j].first][con_end[x+i][y+j].second] = dis[x][y] + 1;
                    q.push_back(con_end[x+i][y+j]);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if((pii){i,j}==s) continue;
            if(grid[i][j] == '.'){
                cout << dis[i][j] << "\n";
            }
        }
    }

    return 0;
}