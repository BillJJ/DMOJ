#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e3+5;

char a[MM][MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '.') a[i][j] = 0;
        }

    for(int t = 1; t--;){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m/2; j++){
                if(a[i][j] == a[i][m-j+1]) continue;
                else if(a[i][j] && !a[i][m-j+1]){
                    a[i][m-j+1] = a[i][j];
                } else if(!a[i][j] && a[i][m-j+1]){
                    a[i][j] = a[i][m-j+1];
                } else{
                    cout << -1; return 0;
                }
            }
        }

        for(int j = 1; j <= m; j++){
            for(int i = 1; i <= n/2; i++){
                if(a[i][j] == a[n-i+1][j]) continue;
                else if(!a[i][j] && a[n-i+1][j]) a[i][j] = a[n-i+1][j];
                else if(!a[n-i+1][j] && a[i][j]) a[n-i+1][j] = a[i][j];
                else{
                    cout << -1; return 0;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            if(!a[i][j]) a[i][j] = 'a';
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}