#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e5+5;

ll a[MM];
map<ll, ll> s;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll n, k; cin >> n >> k;
    for(int i =1, x; i <= n; i++){
        cin >> x;
        s[x]++;
    }

    a[1] = s.begin()->first;
    s.begin()->second--;
    for(int i = 2; i <= n; i++){
        ll x = k-a[i-1];
        auto it = s.lower_bound(x);
        if(it == s.end()){
            cout << "-1\n"; return 0;
        }
        while(it->second == 0){
            s.erase(it);
            it = s.lower_bound(x);
            if(it == s.end()){
                cout << "-1\n"; return 0;
            }
        }

        a[i] = it->first;
        it->second--;
    }
    
    for(int i = 1; i <= n; i++){
        cout << a[i] << " \n"[i == n];
    }
    
    return 0;
}