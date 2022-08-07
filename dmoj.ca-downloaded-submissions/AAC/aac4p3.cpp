#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 1e5+5;

pii a[MM], pref[MM];
set<pii> p;
unordered_map<ll, ll> freq;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i =1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    for(int i =1;i<=m;i++){
        cin >> pref[i].first >> pref[i].second;
        int g = gcd(pref[i].first, pref[i].second);
        pref[i].first /= g, pref[i].second /= g;
        p.insert({pref[i].first, pref[i].second});
    }

    ll res = 0;
    for(auto[pk, pd] : p){
        freq.clear();
        for(int i = 1; i <= n; i++){
            res += freq[a[i].second*pd - pk*a[i].first];
            freq[a[i].second*pd - pk*a[i].first]++;
        }
    }
    cout << res << "\n";
    return 0;
}