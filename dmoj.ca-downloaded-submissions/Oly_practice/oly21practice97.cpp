#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

vector<ll> pos, neg;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        if(x < 0) neg.push_back(x);
        else pos.push_back(x);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<ll>());
    ll res = LONG_LONG_MAX;
    if(pos.size() >= k) res = min(res, pos[k-1]);
    if(neg.size() >= k) res = min(res, -neg[k-1]);

    for(int i = 0; i < neg.size() && i+1 < k; i++){
        if(i+1 + pos.size() < k) continue;
        if(k-i-2 > pos.size()-1) continue;
        res = min(res, -2*neg[i] + pos[k-i-2]);
    }

    for(int i = 0; i < pos.size() && i+1 < k; i++){
        if(i+1 + neg.size() < k) continue;
        if(k-i-2 > neg.size()-1) continue;
        res = min(res, 2*pos[i] - neg[k-i-2]);
    }

    cout << res;
    return 0;
}