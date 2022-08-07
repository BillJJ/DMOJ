#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 255+10, MV=26*26*MM;

int a[MM];
bitset<MV*2> dp[2][MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        a[i] = c-'A'+1;
        a[i] *= a[i];
    }

    int pre=0,cur=1;

    dp[pre][0][MV] = 1;
    for(int i = 1; i <= n; i++){        
        for(int j = 0; j <= i; j++){

            dp[cur][j+1] |= dp[pre][j]<<a[i];
            if(j > 0) dp[cur][j-1] |= dp[pre][j]>>a[i];
            dp[cur][j] |= dp[pre][j];
        }
        swap(pre, cur);
    }


    vector<int> out;
    for(int i = 0; i < MV*2; i++){
        if(dp[pre][0][i]) out.push_back(i-MV);
    }
    cout << out.size() << "\n";
    for(auto &i : out) cout << i << "\n";

    return 0;
}