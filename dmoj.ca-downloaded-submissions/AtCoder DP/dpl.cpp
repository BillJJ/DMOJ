#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 3e3+5;

int a[MM];
ll dp[MM][MM];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int l = n; l >= 1; l--){
        for(int r = l; r <= n; r++){
            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }

    cout << dp[1][n];

    return 0;
}