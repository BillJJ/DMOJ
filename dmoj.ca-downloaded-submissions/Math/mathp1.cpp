#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

ll a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int g = abs(a[1]);
    for (int i = 1; i <= n; ++i) {
        g = gcd(g, abs(a[i]));
    }
    cout << g;

    return 0;
}