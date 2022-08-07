#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 110;

int n;

void solve(){
    int jx, jy;
    if(n&1){
        cout << "1\n";
        cout << (n+1)/2 << " " << (n+1)/2 << "\n";
    } else{
        cout << "2\n";
    }
    cin >> jx >> jy;
    while(jx && jy){
        cout << n+1-jx << " " << n+1-jy << "\n";
        cin >> jx >> jy;
    }
}

signed main() {
//    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> n >> t;
    while(t--){
        solve();
    }

    return 0;
}