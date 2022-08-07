#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

pii a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    a[n+1] = a[1];
    double res = 0;
    for(int i = 1; i <= n; i++){
        res += (a[i+1].first+a[i].first) * (a[i+1].second - a[i].second);
    }
    cout << ceil(abs(res)/2);

    return 0;
}