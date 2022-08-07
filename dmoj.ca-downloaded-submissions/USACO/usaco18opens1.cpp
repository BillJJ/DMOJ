#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5, MV = 5e3+5;

pii a[MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first; a[i].second = i;
    }

    sort(a+1, a+n+1);
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, a[i].second-i);
    }
    cout << res+1;
    return 0;
}