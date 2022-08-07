#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MV = 100000;
ll dp[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, c; scanf("%d%d", &n, &c);

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int v, w; scanf("%d%d", &w, &v);
        for(int j = MV; j >= v; j--){
            dp[j] = min(dp[j], dp[j-v] + w);
        }
    }

    for(int i = MV; i >= 0; i--){
        if(dp[i] <= c){
            printf("%d", i);
            break;
        }
    }

    return 0;
}