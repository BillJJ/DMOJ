#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

typedef pair<ll, ll> pll;
const int MM = 45;

pii a[MM];
map<pll, ll> f[MM], b[MM];

ll ans[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, kx, ky; cin >> n >> kx >> ky;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    for(int i = 1; i <= n/2; i++){
        for(int j = i; j >= 2; j--){
            for(auto[p, r] : f[j-1]){
                f[j][{p.first+a[i].first, p.second+a[i].second}] += r;
            }
        }
        f[1][a[i]]++;
    }

    for(int i = n; i > n/2; i--){
        for(int j = i; j <= n-1; j++){
            for(auto[p, r] : b[j+1]){
                b[j][{p.first+a[i].first, p.second+a[i].second}] += r;
            }
        }
        b[n][a[i]]++;
    }

    for(int i = 1; i <= n/2; i++){
        for(auto[p, r] : f[i]){
            for(int j = 1; j +n/2 <= n; j++){

                if(b[n-j+1].find({kx-p.first, ky-p.second}) != b[n-j+1].end())
                    ans[i+j] += r * b[n-j+1][{kx-p.first, ky-p.second}];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        ans[i] += f[i][{kx, ky}] + b[n-i+1][{kx, ky}];
        cout << ans[i] << "\n";
    }

    return 0;
}