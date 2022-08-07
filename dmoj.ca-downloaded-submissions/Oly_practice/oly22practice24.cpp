#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

bool a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            if(j % i == 0) a[j] ^= 1;
//            cout << a[j] << " ";
//        }
//        cout << "\n";
//    }
    ll res = 0;
    ll cnt = 1, i=1;
    while(i <= n){
        res ++;
        cnt += 2;
        i += cnt;
    }

    cout << res;
    return 0;
}