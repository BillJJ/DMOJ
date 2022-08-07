#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int cost = 0;
    for(int i = 0; i <= n; i++) cost += abs(a[i+1] - a[i]);

    for(int i = 1; i <= n; i++){
        cout << (cost - (abs(a[i+1]-a[i]) + abs(a[i]-a[i-1])) + abs(a[i+1]-a[i-1])) << "\n";
    }

    return 0;
}