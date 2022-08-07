#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

ll a[MM], n;
map<int, int> f;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    f.clear();
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(f.lower_bound(a[i]) == f.end()) {
            res++;
        } else{
            auto it = f.lower_bound(a[i]);
            if(--it->second == 0) f.erase(it);
        }
        f[a[i]]++;
    }


    cout << res << "\n";

    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}