#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 1e5+5;
int vis[MM];
vector<pii> edge[MM]; // dest : type (1==same, 2 == diff)

void colour(int i, int c){
    vis[i] = c;
    for(auto[v, type] : edge[i]){
        if(!vis[v]){
            if(type == 1) colour(v, c);
            else colour(v, ((c-1)^1)+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        char cmd; int a, b;
        cin >> cmd >> a >> b;
        int c = cmd=='S'? 1 : 2;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            res++;
            colour(i, 1);
        }
    }

    for(int i = 1; i <= n; i++){
        for(auto[b, c] : edge[i]){
            if(c == 1 && vis[i] != vis[b]){
                cout << 0; return 0;
            } else if(c==2 && vis[i] == vis[b]){
                cout << 0; return 0;
            }
        }
    }

    cout << 1;
    for(int i = 0; i < res; i++) cout << 0;

    return 0;
}