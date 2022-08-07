#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int blocks[1505][1505];
int girth[1505][1505];
queue<pii> q;

void build(int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            blocks[i][j] += blocks[i-1][j] + blocks[i][j-1] - blocks[i-1][j-1];
        }
    }
}

bool fits(int x, int y, int fat){
    if(x - fat < 0 || y - fat < 0) return false;

    return !(blocks[x][y] - blocks[x-fat][y] - blocks[x][y-fat] + blocks[x-fat][y-fat]);
}

int largest(int i, int j, int x){
    while(!fits(i, j, x)){
        x--;
    }
    return x;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;
            if(c == 'X') {
                blocks[i][j] = 1;
                girth[i][j] = -1;
            }
        }
    }
    build(n, m);

    int x = 1;
    while(1) {
        if(fits(x,x,x) && x <= m && x <= n) x++;
        else {x--;
            break;}
    }

    girth[x][x] = x;
    q.push({x, x});
    while(!q.empty()){
        auto[i, j] = q.front(); q.pop();
        x = girth[i][j];

        int down = largest(i+1, j, x);
        if(i+1 <= n && girth[i+1][j] != -1 && girth[i+1][j] < down){
            girth[i+1][j] = down;
            q.push({i+1, j});
        }
        int right = largest(i, j+1, x);
        if(j+1 <= m && girth[i][j+1] != -1 && girth[i][j+1] < right){
            girth[i][j+1] = right;
            q.push({i, j+1});
        }
        int up = largest(i-1, j, x);
        if(i-1 >= 1 && girth[i-1][j] != -1 && girth[i-1][j] < up){
            girth[i-1][j] = up;
            q.push({i-1, j});
        }
        int left = largest(i, j-1, x);
        if(j-1 >= 1 && girth[i][j-1] != -1 && girth[i][j-1] < left){
            girth[i][j-1] = left;
            q.push({i, j-1});
        }

    }

    cout << girth[n][m];

    return 0;
}