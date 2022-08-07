#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    sort(a+1, a+m+1);
    vector<int> d;
    for(int i = 1; i < m; i++){
        d.push_back(a[i+1] - a[i]);
    }

    sort(d.begin(), d.end(), greater<int>());
    ll res = 0;
    for(int i = m; i > n; i--){
        res += d.back();
        d.pop_back();
    }
    cout << res;

    return 0;
}