#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    ll total = 0;
    while(n--){
        ll a, b; cin >> a >> b;
        total += a*b;
        total %= k;
    }

    cout << total;

    return 0;
}