#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<ll> h (n), s(n); for(ll &x:h) cin >> x;
    for(ll &x:s) cin >> x;

    sort(h.begin(), h.end(), greater<ll>());
    sort(s.begin(), s.end(), greater<ll>());

    ll total = 1;
    for(int i = 0; i < n; i++){
        ll fits = 0;
        for(ll &stall : s) if(stall >= h[i]) fits++;

        total *= (fits - i);
    }
    cout << total;
    return 0;
}