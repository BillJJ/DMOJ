#include <bits/stdc++.h>
using namespace std;

int dis[1001][1001];

int main() {

    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int r, c; cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char c; cin >> c;
            if(c == '#'){
                dis[i][j] = -1;
            }
        }
    }
    dis[0][0] = 1;
    for(int i = 0; i+1 < c; i++){
        if(dis[0][i+1] != -1){
            dis[0][i+1] = dis[0][i];
        }
    }
    for(int i = 0; i+1 < r; i++){
        if(dis[i+1][0] != -1){
            dis[i+1][0] = dis[i][0];
        }
    }

    for(int i = 1; i < r; i++){
        for(int j = 1; j < c; j++){
            if(dis[i][j] == -1) continue;
            int one = 0, two = 0;
            if(dis[i-1][j] != -1){
                one = dis[i-1][j];
            }
            if(dis[i][j-1] != -1){
                two = dis[i][j-1];
            }
            dis[i][j] = (one + two) % 1000000007;
        }
    }
    cout << dis[r-1][c-1];

    return 0;
}