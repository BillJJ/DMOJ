#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e4+5;

ll a[MM];

int main()  {
//    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    if(n & 1){
        for(int i = 2; i <= n; i+=2){
            cout << "? " << i << " " << i+1 << '\n';
            ll j; cin >> j;
            cout << "? " << i << " " << i+1 << '\n';
            ll j2; cin >> j2;
            a[i] = (j2/2) + j;
            a[i+1] = j2/2;
        }

        cout << "? 1 " << n << '\n';
        ll u; cin >> u;
        a[1] = u+a[n]*2;
    } else{
        for(int i = 1; i <= n; i+=2){
            cout << "? " << i << " " << i+1 << '\n';
            ll j; cin >> j;
            cout << "? " << i << " " << i+1 << '\n';
            ll j2; cin >> j2;
            a[i] = (j2/2) + j;
            a[i+1] = j2/2;
        }
    }

    cout << "! ";
    for(int i = 1; i < n; i++){
        cout << a[i] << " ";
    }
    cout << a[n] <<'\n';

    return 0;
}