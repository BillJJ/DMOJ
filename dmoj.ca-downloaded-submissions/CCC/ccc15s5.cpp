#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 3e3+5;

int a[MM], b[101], n, m;

int dp[MM][2][101][101]; // first i pies : picked last pie : # of wasted bag pies : # of used bag pies : max sum given these conditions

int f(int i, bool eat, int waste, int used){
    if(waste+used > m) return INT_MIN;
    if(dp[i][eat][waste][used]) return dp[i][eat][waste][used];

    int res = 0;

    if(i == n+1){
        if(eat){
            res = max(res, f(i, 0, waste, used+1) + b[m-used]);
            res = max(res, f(i, 1, waste+1, used+1) + b[m-used]);
        } else{
            res = max(res, f(i, 0, waste+1, used+1) + b[m-used]);
        }
        dp[i][eat][waste][used] = res;
        return res;
    }

    if(eat){
        res += a[i];
        res = max(res, f(i+1, 0, waste, used) + a[i]);
        res = max(res, f(i+1, 1, waste+1, used) + a[i]);
    } else{
        res = max(res, f(i+1, 1, waste, used));
        res = max(res, f(i+1, 0, waste, used));
        res = max(res, f(i+1, 0, waste, used+1) + b[m-used]);
    }
    dp[i][eat][waste][used] = res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> b[i];

    sort(b+1, b+m+1);

    f(1, 0, 0, 0);
    f(1, 1, 0, 0);

    cout << max(dp[1][0][0][0], dp[1][1][0][0]);

    return 0;
}