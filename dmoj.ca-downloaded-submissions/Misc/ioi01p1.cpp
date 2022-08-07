#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const int MAXN = 1030;
ll bit[MAXN][MAXN];
int s;
void update(int x, int y, ll v){
    for(int i = x; i <= s; i += i&-i){
        for(int j = y; j <= s; j += j &-j){
            bit[i][j] += v;
        }
    }
}

ll prefix_sum(int x, int y){
    ll ret = 0;
    for(int i = x; i > 0; i-= i&-i){
        for(int j = y; j > 0; j -= j & -j){
            ret += bit[i][j];
        }
    }
    return ret;
}

ll sum(int l, int b, int r, int t){
    return prefix_sum(r, t) - prefix_sum(r, b-1) - prefix_sum(l-1, t)
        + prefix_sum(l-1, b-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int cmd; cin >> cmd >> s;
    while(1){
        cin >> cmd;
        if(cmd == 3) break;

        if(cmd == 1){
            int x, y, a; cin >> x >> y >> a;
            x++, y++;
            update(x, y, a);
        }
        else if(cmd == 2){
            int l, b, r, t; cin >> l >> b >> r >> t;
            l++, b++, r++, t++;
            cout << sum(l, b, r, t) << '\n';
        }
    }

    return 0;
}