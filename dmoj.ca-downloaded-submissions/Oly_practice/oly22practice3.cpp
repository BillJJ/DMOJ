#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5, MV=5e5+5;

int a[MV], b[MV];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1, x; i <= n; i++) {
        cin >> x; a[x]++;
    }

    ll res = 0;
    for(int i = 1; i < MV; i++){
        res += a[i]*(a[i]-1);
        for(int j = i+i; j < MV; j += i){
            res += a[i]*a[j];
        }
    }

    cout << res;

    return 0;
}