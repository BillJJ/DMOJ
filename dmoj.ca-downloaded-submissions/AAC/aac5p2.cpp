#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e5+5, mod=1e9+7;

ll a[MM];

int main() {
//    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    ll mi=LONG_LONG_MAX, mx=0;
    for(int i = 2; i <= n; i++){
        cout << "? 1 " << i << "\n" << flush;
        cin >> a[i];
        mi = min(mi, a[i]), mx = max(mx, a[i]);
    }

    if(mx == n){
        a[1] = 1;
        cout << "! 1" << flush;
        for(int i = 2; i <= n; i++){
            cout << " " << a[i] << flush;
        }
        cout << "\n" << flush;
    } else{
        int a2 = a[2]/mi;
        a[1] = a[2]/a2;
        cout << "! " << a[1] << flush;
        for(int i = 2; i <= n; i++){
            cout << " " <<  a[i]/a[1] << flush;
        }
        cout << "\n" << flush;
    }

    return 0;
}