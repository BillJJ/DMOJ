#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int a[4][MM];
ll two[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= 3; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];

    for(int i = 1; i <= 3; i++) sort(a[i]+1, a[i]+n+1);

    for(int i = 1; i <= n; i++){
        two[i] = lower_bound(a[1]+1, a[1]+n+1, a[2][i]) - a[1]-1;
        two[i] += two[i-1];
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        res += two[lower_bound(a[2]+1, a[2]+n+1, a[3][i]) - a[2]-1];
    }

    cout << res;
    return 0;
}