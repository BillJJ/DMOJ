#include <bits/stdc++.h>
using namespace std;

int grid[26][26];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int r, c; cin >> r >> c;
    int k; cin >> k;
    while(k--){
        int a, b;
        cin >> a >> b;
        grid[a][b] = -1;
    }
    grid[1][1] = 1;
    for(int i = 1; i <= c; i++){
        if(grid[1][i] == -1)
            break;
        grid[1][i] = 1;
    }

    for(int i = 1; i <= r; i++){
        if(grid[i][1] == -1) break;
        grid[i][1] = 1;
    }

    for(int i = 2; i <= r; i++){
        for(int j = 2; j <= c; j++){
            if(grid[i][j] == -1) continue;

            if(grid[i][j-1] != -1)
                grid[i][j] += grid[i][j-1];
            if(grid[i-1][j] != -1)
                grid[i][j] += grid[i-1][j];
        }
    }

    cout << grid[r][c];

    return 0;
}