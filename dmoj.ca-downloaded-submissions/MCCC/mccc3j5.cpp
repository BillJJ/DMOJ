#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e3+5;

pii a[MM];
int n, m;

bool check(int mask){
    for(int i = 1; i <= m; i++){
        auto[x, y] = a[i];
        if(mask & (1<<(x-1)) && mask&(1<<(y-1))) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i].first >> a[i].second;
    }
    
    int res = 0;
    for(int i = (1<<n)-1; i >= 0; i--){
        if(check(i)){
            res = max(res, __builtin_popcount(i));
        }
    }
    cout << res << "\n";

    return 0;
}