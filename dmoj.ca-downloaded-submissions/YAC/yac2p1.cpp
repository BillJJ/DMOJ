#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1.5e3+5;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        double a, b, c, d; cin >> a >> b >> c >> d;
        if(a*c < (b-a)*(d-c)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}