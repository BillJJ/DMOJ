#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

int a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    if((n&1)^(k&1)){
        cout << -1 << "\n"; return 0;
    }

    for(int i = 1+k; i <= n; i+= 2){
        a[i] = 1;
    }

    for(int i = 1; i < n; i++){
        cout << a[i] << " ";
    }
    cout << a[n] << "\n";

    return 0;
}
