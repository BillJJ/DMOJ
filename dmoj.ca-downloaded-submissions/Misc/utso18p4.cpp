#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

vector<pii> a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1;i <= n; i++){
        int k, m; cin >> k >> m;
        a[k+m].push_back({k, m});
    }

    ll res = 0;
    for(int i = 0; i < MM; i++){
        sort(a[i].begin(), a[i].end());

        int l = 0, r = a[i].size()-1;
        ll k = 0, m = 0;
        while(l <= r){
            if(k <= m){
                k += a[i][r].first;
                r--;
            } else{
                m += a[i][l].second;
                l++;
            }
        }
        res = max(res, min(k, m));
    }

    cout << res;

    return 0;
}