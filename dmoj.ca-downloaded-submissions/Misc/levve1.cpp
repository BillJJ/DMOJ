#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, p; cin >> n;
    while(n--){
        cin >> p;
        cout << (ll)ceil((-1 + sqrt(1-4*(2-2*p)))/2) << '\n';
    }

    return 0;
}