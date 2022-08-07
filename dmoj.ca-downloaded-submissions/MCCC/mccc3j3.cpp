#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int, int> pii;

const int MM = 1e6+5;

string s, t;
int f[200];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int dfn, fdn; cin >> dfn >> fdn >> s >> t;
    int res = 0, great=0;

    for(char c : s){
        f[c]++;
        great = max(great, f[c]);
    }
    int least = f[t[0]];
    for(char c : t){
        res += f[c];
        least = min(least, f[c]);
    }
    res += -least + great;
    cout << res << "\n";

    return 0;
}