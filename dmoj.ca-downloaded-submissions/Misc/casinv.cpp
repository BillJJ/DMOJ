#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

ll r[MM], c[MM], psa[MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> r[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    sort(r+1, r+n+1);
    sort(c+1, c+n+1);

    for(int i = 1; i <= n; i++){
        psa[i] = psa[i-1] + c[i];
    }

    if(c[n] != r[n]){
        cout << -1; return 0;
    }

    ll total = 0;
    for(int i = 1; i <= n; i++){
        int greater = lower_bound(c+1, c+n+1, r[i])-c;
        total += psa[greater]-(c[greater]-r[i]) + (n-greater)*r[i];
    }

    cout << total;

    return 0;
}