#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MM = 2e5+5;

ll a[MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    bool flag = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < m) flag = 1;
    }

    if(!flag) {cout << 0; return 0;}

    ll run = a[1];
    int best = 0;
    for(int l = 1, r = 1; l <= n; l++){
        while(r+1 <= n && run+a[r+1] < m) {
            run+=a[r+1];
            r++;
        }
        best = max(best, r-l+1);
        run -= a[l];
    }

    cout << best;
    return 0;
}