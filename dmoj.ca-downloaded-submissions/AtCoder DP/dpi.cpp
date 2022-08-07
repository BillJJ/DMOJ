#include <bits/stdc++.h>
using namespace std;

double dp[3001][3001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        double h; cin >> h; double t = 1-h;
        //tail events: 0 to i-1
        for(int j = 0; j < i; j++){
            dp[i][j] += dp[i-1][j] * t;
        }
        //head events: 1 to i
        for(int j = 1; j <= i; j++){
            dp[i][j] += dp[i-1][j-1] * h;
        }
        if(i == 1){
            dp[i][0] = t; dp[i][1] = h;
        }
    }
    double total = 0;
    for(int i = 1; i <= n; i++){
        if(i*2 > n) total += dp[n][i];
    }
    cout << setprecision(10);
    cout << total;
    return 0;
}