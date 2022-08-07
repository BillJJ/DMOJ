#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int pos[MM], neg[MM], a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int x,i = 1; i <= n; i++){
        cin >> x;
        a[i] -= x;
        if(a[i] > 0) pos[i] = a[i];
        else neg[i] = -a[i];
    }

    ll res= 0;
    for(int i = 1; i <= n; i++){
        if(pos[i] > pos[i-1]) res += pos[i]-pos[i-1];
        if(neg[i] > neg[i-1]) res += neg[i]-neg[i-1];
    }
    cout << res;

    return 0;
}