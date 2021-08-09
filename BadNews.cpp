#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

char grid[26][26];
bool vis[26][26];
pii dirc[] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
int n, q;

bool dfs(int x, int y, string s){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    if(grid[x][y] != s[0]) return false;
    if(vis[x][y]) return false;

    vis[x][y] = 1;
    for(auto [i, j] : dirc){
        if(dfs(x+i, y+j, s.substr(1, s.size()-1))) return true;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];   
        }   
    }

    while(q--){
        memset(vis, 0, sizeof vis);
        string s; cin >> s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i, j, s)){
                    cout << "good puzzle!\n";
                    goto endloop;
                }   
            }   
        }
        cout << "bad puzzle!\n";
        endloop:
    }

    return 0;
}