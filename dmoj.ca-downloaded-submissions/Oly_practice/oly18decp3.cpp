#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

ll a[MM];
set<ll> num;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(num.empty() || m-a[i] < 0 || *num.begin() > m-a[i]) {
            num.insert(a[i]);
            continue;
        }

        auto it = num.lower_bound(m-a[i]);
        while(*it > m-a[i] || it == num.end()) it--;
        res = max(res, a[i]+*it);
        num.insert(a[i]);
    }
    cout << res;

    return 0;
}