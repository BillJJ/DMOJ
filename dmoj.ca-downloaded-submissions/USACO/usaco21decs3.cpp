#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5, MV=1e4+5;

ll fa[MM], fs[MM], add[MM], sub[MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        fa[x]++, fs[y]--;
    }
    for(int i = 0; i <= 2*m; i++){
        if(fa[i] == 1) add[i*2]++;
        else add[i*2] += fa[i] * fa[i];
        for(int j = i+1; j <= 2*m-i; j++){
            add[i+j] += fa[i] * fa[j] * 2;
        }
    }

    for(int i = 0; i <= 2*m; i++){
        if(fs[i] == 1) sub[i*2 + 1]++;
        else sub[i*2 + 1] += fs[i] * fs[i];

        for(int j = i+1; j <= 2*m-i; j++){
            sub[i+j + 1] += fs[i] * fs[j] * 2;
        }
    }

    ll res = 0;
    for(int i = 0; i <= 2*m; i++){
        res += add[i] - sub[i];
        cout << res << "\n";
    }

    return 0;
}