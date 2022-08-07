#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;

const int MM = 1e6+5;

pii a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int res = 0;
    int left = INT_MAX;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++){
        left = min(left, a[i-1].second - a[i].first);
        a[i].second += a[i-1].second;
        res = max(res, a[i].second-a[i].first - left);
    }

    cout << res;

    return 0;
}