#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e5+5, MV=655;

int p[MV][MV];

pii a[MM];
pii ans[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
        p[652-a[i].first][652-a[i].second]++;
    }

    for(int i = 0; i < MV; i++){
        for(int j = 0; j < MV; j++){
            if(i == 0 && j == 0) continue;

            if(i == 0){
                p[i][j] += p[i][j-1];
            }
            else if(j == 0){
                p[i][j] += p[i-1][j];
            }
            else{
                p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        ans[i].first = (p[652 - a[i].first - 1][652 - a[i].second - 1]+1);
    }

    memset(p, 0, sizeof p);

    for(int i = 1; i <= n; i++){
        p[a[i].first][a[i].second]++;
    }

    for(int i = 0; i < MV; i++){
        for(int j = 0; j < MV; j++){
            if(i == 0 && j == 0) continue;

            if(i == 0){
                p[i][j] += p[i][j-1];
            }
            else if(j == 0){
                p[i][j] += p[i-1][j];
            }
            else{
                p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
            }
        }
    }


    for(int i = 1; i <= n; i++){
        int x = n;
        if(a[i].first != 0 && a[i].second != 0){
            x -= p[a[i].first-1][a[i].second-1];
        }
        if(a[i].second == 650){
            if(a[i].first) x -= p[a[i].first][0] - p[a[i].first - 1][0];
            else x -= p[a[i].first][0];
        }
        if(a[i].first == 650){
            if(a[i].second) x -= p[0][a[i].second] - p[0][a[i].second-1];
            else x -= p[0][0];
        }

        ans[i].second = x;
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}