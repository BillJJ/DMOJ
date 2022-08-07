#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

int a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int l, r; cin >> l >> r;
        a[l]++, a[r+1]--;
    }

    for (int i = 1; i <= n; ++i) {
        a[i] += a[i-1];
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if(a[i] == m) res++;
    }
    cout << res;

    return 0;
}