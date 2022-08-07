#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7, prime = 131;

const int MM = 1e6+5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    unsigned long long m, n; cin >> m >> n;

    for(__uint128_t i = m;i <= n; i++){
        cout << (unsigned long long)i << "\n";
    }

    return 0;
}