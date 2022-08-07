#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

char grid[26][26];
bool vis[26][26];
int n, q;
string s;

bool dfs(int x, int y, int index){
    if(index == s.size()) return true;
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    if(grid[x][y] != s[index]) return false;
    if(vis[x][y]) return false;

    vis[x][y] = 1;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(dfs(x+i, y+j, index+1)) return true;
        }
    }
    vis[x][y] = false; return false;
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
        cin >> s;
        bool stop = 0;
        for (int i = 0; i < n && !stop; i++) {
            for (int j = 0; j < n && !stop; j++) {
                if (grid[i][j] == s[0])
                    if (dfs(i, j, 0)) {
                        cout << "good puzzle!\n";
                        stop = 1;
                    }
            }
        }
        if (!stop)
            cout << "bad puzzle!\n";
    }

    return 0;
}