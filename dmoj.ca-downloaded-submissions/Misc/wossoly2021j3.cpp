#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 18, MV=1e6;

ll d[7] = {1, 5, 10, 50, 100, 500, 1000}, a[7];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    for(int i = 6; i >= 0; i--){
        a[i] = n/d[i];
        n %= d[i];
    }

    for(ll &i : a){
        cout << i << " ";
    }

    return 0;
}