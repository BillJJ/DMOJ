#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

int a[MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    cout << accumulate(a, a+m, 0L);
}