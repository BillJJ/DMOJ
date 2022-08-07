#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1.5e3+5;

ll a[MM][MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n,m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j= 1; j <=m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 0){
                a[i][j] = max(a[i][j-1], a[i-1][j]) + 1;
            }
            if(max(a[i-1][j], a[i][j-1]) >= a[i][j]){
                cout << -1; return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j= 1; j <=m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}