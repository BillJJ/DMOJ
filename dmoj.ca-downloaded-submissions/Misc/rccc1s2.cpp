#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int MM = 1.5e3+5, mod=1e9+7;

ll a[MM];

unordered_map<ll, ll> f, cnt[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    for(int i =1; i <= n; i++){
        cin >> a[i];
    }

    ll res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){

            ll mult = a[i]*a[j];
            res += (f[mult]-cnt[i][mult] - cnt[j][mult]) * 8;

            cnt[i][mult]++;
            cnt[j][mult]++;
            f[mult]++;
        }
    }

    cout << res << "\n";

    return 0;
}