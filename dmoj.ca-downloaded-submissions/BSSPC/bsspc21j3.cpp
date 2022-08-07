#include <bits/stdc++.h>
using namespace std;

int grid[1001][1001][3]; //0:red, 1:yellow, 2:blue
int m, n;

int check(int c){
    int total = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j == 0){
                if(grid[i][j][c]) total++;
            }
            else{
                if(grid[i][j][c] && !grid[i][j-1][c]) total++;
            }
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> m >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;

            switch(c){
                case 'R': grid[i][j][0]++; break;
                case 'Y': grid[i][j][1]++; break;
                case 'U': grid[i][j][2]++; break;
                case 'O': grid[i][j][0]++; grid[i][j][1]++; break;
                case 'G': grid[i][j][1]++; grid[i][j][2]++; break;
                case 'P': grid[i][j][0]++; grid[i][j][2]++; break;
                case 'B': grid[i][j][0]++; grid[i][j][1]++; grid[i][j][2]++; break;
                case '.': break;
            }
        }
    }

    cout << check(0) << ' ' << check(1) << ' ' << check(2);

    return 0;
}