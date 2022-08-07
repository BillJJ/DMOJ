#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
typedef pair<int, int> pii;
typedef vector<vector<bool>> vvb;

int vis[1000][1000] = {};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;
    pii start, end;
    for(int i = 0; i < r;i++){
        for(int j = 0; j < c;j++){
            char ch; cin >> ch;
            switch(ch){
                case 's':
                    start = pii(i,j);
                    break;
                case 'e':
                    end = pii(i, j);
                    break;
                case 'X':
                    vis[i][j] = -1;
                    break;
            }
        }
    }

    deque<pii> q;
    q.push_back(start);

    int dirc[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

    while(!q.empty()){
        pii m = q.front(); q.pop_front();
        int x = m.first;
        int y = m.second;

        if(m == end){
            break;
        }

        for(int i = 0; i < 4; i++){
            if(vis[x + dirc[i][0]][y + dirc[i][1]] == 0){

                if(x + dirc[i][0] < 0 || x + dirc[i][0] >= r){
                    continue;
                }
                else if(y + dirc[i][1] < 0 || y + dirc[i][1] >= c){
                    continue;
                }

                vis[x + dirc[i][0]][y + dirc[i][1]] = vis[x][y] + 1;
                q.push_back(pii(x + dirc[i][0], y + dirc[i][1]));
            }
        }
    }

    if(!vis[end.first][end.second]){
        cout << "-1";
    }
    else{
        cout << vis[end.first][end.second] - 1;
    }
}