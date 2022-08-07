#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int MM = 2e5+5;

ll a[MM];
ll pma[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    pma[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ll x = pma[i-1] * a[i] / gcd(pma[i-1], a[i]);

        if(x > 1e9){
            pma[i] = 0;
        } else{
            pma[i] = x;
        }
    }

    while(q--){
        int t; cin >> t;
        if(t == 0){cout << "-1\n"; continue;}
        int l=1, r=n;
        while(r-l>5){
            int mid= (l+r)/2;
            if(pma[mid] != 0 && t%pma[mid] == 0){l=mid+1;}
            else r = mid;
        }
        bool flag = 0;
        for(int i = l; i <= r; i++){
            if( pma[i] == 0 || t%pma[i] != 0){
                cout << i << "\n";
                flag = 1;
                break;
            }
        }
        if(!flag)
            cout << -1 << "\n";
    }

    return 0;
}