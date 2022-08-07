#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

int a[MM];

int f[MM],  b[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int pre = 0;
    for (int i = 1; i <= n; ++i) {
        if(a[i] == pre+1){
            pre++;
        }
        f[i] = pre;
    }

    pre = 0;
    int res = 0; // does 1 2 1 count as a pyramid?
    for (int i = n; i >= 2; --i) {
        if(a[i] == pre+1){
            pre++;
        }
        b[i] = pre;
        if(f[i-1] <= b[i]) res = max(res, min(f[i-1], b[i]));
    }
    cout << res;

    return 0;
}