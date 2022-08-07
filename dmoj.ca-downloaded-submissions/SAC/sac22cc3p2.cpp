#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 110;

signed main() {
   ios_base::sync_with_stdio(0); cin.tie(0);

    ll m; cin >> m;
    cout << setprecision(8) << (5.0 + sqrt(25 - 4*12*(1-m)))/(24);
    

    return 0;
}