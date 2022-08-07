#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e5+5;
const ll mod=1e12;

ll a[MM];
ll w[MM];
unordered_map<ll, ll> freq;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    srand(time(0));
    ll k = 0;
    for(int i = 1; i <= m; i++){
        w[i] = rand()%mod+1;
        k += w[i];
    }
    freq[0] = 1;
    ll res = 0, run=0;
    for(int i = 1; i <= n; i++){
        run = (run+w[a[i]]) % k;
        res += freq[run];
        freq[run]++;
    }

    cout << res;

    return 0;
}