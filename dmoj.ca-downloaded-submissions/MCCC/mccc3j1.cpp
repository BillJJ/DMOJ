#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll a, b, c; cin >> a >> b >> c;
    if(abs(b*b-a) < abs(c*c-a)) cout << 1;
    else cout << 2;
    cout << '\n';
    return 0;
}