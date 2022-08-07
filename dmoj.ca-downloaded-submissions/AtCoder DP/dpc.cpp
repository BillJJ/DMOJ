#include <bits/stdc++.h>
using namespace std;

int a[100001][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1]>> a[i][2];
        a[i][0] += max(a[i-1][1], a[i-1][2]);
        a[i][1] += max(a[i-1][0], a[i-1][2]);
        a[i][2] += max(a[i-1][1], a[i-1][0]);
    }

    cout << max({a[n][0], a[n][1], a[n][2]});

    return 0;
}