#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;

int diff[1005][1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int l, b, r, t; cin >> l >> b >> r >> t;
        diff[l][b]++;
        diff[l][t]--;
        diff[r][b]--;
        diff[r][t]++;
    }

    for(int i = 1; i <= 1000; i++) diff[0][i] += diff[0][i-1];
    for(int i = 1; i <= 1000; i++) diff[i][0] += diff[i-1][0];

    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
        }
    }
    
    int res = 0;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            if(diff[i][j] == k) res++;
        }
    }

    cout << res;

    return 0;
}