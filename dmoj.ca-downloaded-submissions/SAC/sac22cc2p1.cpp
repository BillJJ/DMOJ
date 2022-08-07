#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, string> pis;

const int MM = 1e6+5;

pis a[101];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    while(k--){
        int x; cin >> x;
        for(int i = 1; i<= n; i++){
            if(a[i].first <= x) {
                cout << a[i].second << "\n";
                a[i].first = 1e5;
            }
        }
    }


    return 0;
}