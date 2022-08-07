#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;
ll diffq[MM], diffl[MM], diffc[MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, t; cin >> n >> t;
    for(ll i = 0, l, r, a, b, c; i < n; i++){
        cin >> l >> r >> a >> b >> c;
        diffq[l] += a; diffq[r+1] -= a;
        ll linear = (-2*a*l+b); diffl[l] += linear; diffl[r+1] -= linear;
        ll cons = a*l*l-b*l+c; diffc[l] += cons; diffc[r+1] -= cons;
    }

    for(ll i = 1; i <= t; i++){
        diffq[i] += diffq[i-1];
        diffl[i] += diffl[i-1];
        diffc[i] += diffc[i-1];
        cout << diffq[i] * i*i + diffl[i]*i + diffc[i] << ' ';
    }

    return 0;
}