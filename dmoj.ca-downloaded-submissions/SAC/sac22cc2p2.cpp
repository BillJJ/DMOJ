#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, string> pis;

const int MM = 1e6+5;

int bit[505][505];

void add(int x, int y){
    for(int i = x; i <= 500; i+= i&-i){
        for(int j = y; j <= 500; j += j&-j){
            bit[i][j]++;
        }
    }
}

int query(int x, int y){
    int res = 0;
    for(int i = x; i > 0; i-= i&-i){
        for(int j = y; j > 0; j -= j & -j){
            res += bit[i][j];
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    int res = 0;

    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int x, y; cin >> x >> y;
            add(x, y);
        } else{
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            res += query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
        }
    }

    cout << res;

    return 0;
}