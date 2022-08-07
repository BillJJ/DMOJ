#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

pii a[MM];
int b[MM];

priority_queue<int> q;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a+1, a+n+1, greater<pii>());

    int idx = 1;
    ll res = 0;
    
    for(int i = a[1].first; i >= 1; i--){
        while(a[idx].first >= i){
            q.push(a[idx].second);
            idx++;
        }

        if(q.size()) {res += q.top(); q.pop();}
    }
    cout << res;
    
    return 0;
}