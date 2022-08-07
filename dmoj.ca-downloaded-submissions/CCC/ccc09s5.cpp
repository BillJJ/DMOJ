#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1005][30005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int m, n, k; cin >> m >> n >> k;

    while(k--){
        int x, y, r, b; cin >> x >> y >> r >> b;

        for(int i = 0; i+x <= min(r+x, n); i++){
            int j = sqrt((ll)r*r - (ll)i*i);
            a[x+i][max(0, y-j)] += b;
            a[x+i][min(m, y+j)+1] -= b;
        }

        for(int i = 1; x-i >= max(0, x-r); i++){
            int j = sqrt((ll)r*r - (ll)i*i);
            a[x-i][max(0, y-j)] += b;
            a[x-i][min(m, y+j) + 1] -= b;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] += a[i][j-1];
        }
    }

    int highest = 0;
    int total = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] > highest){
                highest = a[i][j];
                total = 1;
            }else if(a[i][j] == highest){
                total++;
            }
        }
    }

    cout << highest << '\n' << total;

    return 0;
}