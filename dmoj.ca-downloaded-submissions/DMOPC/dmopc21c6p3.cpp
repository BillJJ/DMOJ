#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1.5e3+5;

int a[MM][MM];
struct col{
    int d, c, x, y;
};
auto comp = [](col x, col y){if(x.d==y.d) return x.c > y.c; return x.d > y.d;};
priority_queue<col, vector<col>, decltype(comp)> q (comp);

int main() {

    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            if(a[i][j]){
                q.push({0, a[i][j], i, j});
            }
        }
    }

    int dirc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!q.empty()){
        auto[d, c, x, y] = q.top(); q.pop();
        if(d == k) continue;

        for(auto[i, j] : dirc){
            if(x+i<1||x+i>n||y+j<1||y+j>m|| a[x+i][y+j]) continue;
            q.push({d+1, c, x+i,j+y});
            a[x+i][y+j] = c;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}