#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e3+5;

set<char> a;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    char w; cin >> w;
    int n; cin >> n;
    a.insert(w);
    for(int i = 1; i <= n; i++){
        char u, v; cin >> u >> v;

        if(v == w) w = u;
        a.insert(w);
    }
    cout << w << "\n";
    cout << a.size() << "\n";
    return 0;
}