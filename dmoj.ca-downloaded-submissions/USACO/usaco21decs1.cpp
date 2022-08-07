#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 2e5+5, MV=1e4+5;

vector<pii> a;
vector<ll> val; // 2 cow value : 1 cow value

ll cost(int left, int right){
    ll res = 0, run = 0;
    for(int l = left+1, r=left+1; r < right; r++){
        while(2*a[l].first + a[right].first <= a[left].first + 2*a[r].first){
            run -= a[l].second;
            l++;
        }
        run += a[r].second;
        res = max(res, run);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k, m, c; cin >> k >> m >> c;
    for(int i = 1,p, t; i <= k; i++){
        cin >> p >> t;
        a.push_back({p, t});
    }
    for(int i = 0, x; i < m; i++){
        cin >> x; a.push_back({x, -1});
    }
    sort(a.begin(), a.end());
    if(a.front().second != -1) a.insert(a.begin(), (pii){-1e9, -1});
    if(a.back().second != -1) a.push_back({1e18, -1});

    for(int l=0,r=1; r < a.size(); r++){
        ll run = 0;
        l = r-1;
        while(a[r].second != -1){
            run += a[r].second;
            r++;
        }
        if(run == 0) continue;

        int d = cost(l, r);
        if(d == run) val.push_back(d);
        else val.push_back(d), val.push_back(run-d);
    }

    sort(val.begin(), val.end(), greater<ll>());
    ll res = 0;
    for(int i = 0; i < val.size(); i++){
        if(i < c) res += val[i];
    }

    cout << res;

    return 0;
}