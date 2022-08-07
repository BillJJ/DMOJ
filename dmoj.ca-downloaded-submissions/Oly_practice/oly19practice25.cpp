#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define print(x) {for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<'\n';}cout<<'\n';}

ll a[5005][5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);


    int n, m, k; cin >> n >> m >> k;
    while(k--){
        int x, y, X, Y; cin >> x >> y >> X >> Y;
        a[x][y]++; a[x][Y+1]--; a[X+1][y]--; a[X+1][Y+1]++;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    int q; cin >> q;
    while(q--){
        int x, y, X, Y; cin >> x >> y >> X >> Y;
        cout << a[X][Y] - a[x-1][Y] - a[X][y-1] + a[x-1][y-1] << '\n';
    }

    return 0;
}