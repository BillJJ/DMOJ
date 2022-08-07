#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MM = 1e6+5;

ll psa[MM], least[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> psa[i];
    }

    ll res = 0;
    for(int i = 1; i <= n; i++){
        psa[i] += psa[i-1];
        least[i] = psa[i];
        if(i >= k){
            least[i] = min(least[i], least[i-k]);
            res = max(res, psa[i]-least[i]);
        }
    }
    cout << res;

    return 0;
}