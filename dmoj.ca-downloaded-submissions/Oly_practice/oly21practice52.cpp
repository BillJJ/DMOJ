#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e5+5, MV = 6e4 + 5;

ll dp[MV];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    ll n, c, sumw=0, sumv=0; cin >> n >> c;

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1, v, w; i <= n; i++){
        cin >> v >> w;
        for(int j = MV-1; j-w >= 0; j--){
            dp[j] = min(dp[j], dp[j-w]+v);
        }
        sumw += w;
        sumv += v;
    }
    if(sumw <= c){
        cout << sumv << "\n";
    } else{
        ll least = INT_MAX;
        for(int i = sumw-c; i < MV; i++){
            least = min(least, dp[i]);
        }
        cout << sumv-least << "\n";
    }

    return 0;
}