#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

pii w[MM], b[MM]; // w < b
set<int> wy;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i].first >> w[i].second;
    for(int i = 1; i <= n; i++) cin >> b[i].first >> b[i].second;

    sort(w+1, w+n+1);
    sort(b+1, b+n+1);

    int wi = 1, res = 0;
    for(int i = 1; i <= n; i++){
        while(wi <= n && w[wi].first < b[i].first) wy.insert(w[wi++].second);

        auto it = wy.lower_bound(b[i].second);
        if(it == wy.begin()) continue;
        it--;
        wy.erase(it);
        res++;
    }

    cout << res;

    return 0;
}