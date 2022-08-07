#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second

const int MM = 3e3+5;

struct tri{
    pii a, b, c;
} tree[MM];

bool bounded(tri t, ll qx, ll qy){
    return (min(t.a.x, t.c.x) <= qx && qx <= max(t.a.x, t.c.x) &&
    min(t.a.y, t.b.y) <= qy && qy <= max(t.a.y, t.b.y) &&
    abs(qx-t.a.x)*abs(qy-t.a.y) <= abs(qx-t.c.x)*abs(qy-t.b.y));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> tree[i].a.x >> tree[i].a.y >> tree[i].b.x >> tree[i].b.y >>tree[i].c.x >> tree[i].c.y;
    }

    while(q--){
        int qx, qy; cin >> qx >> qy;
        int res = 0;

        for(int i = 1; i <= n; i++){
            if(bounded(tree[i], qx, qy)) res++;
        }
        cout << res << "\n";
    }

    return 0;
}