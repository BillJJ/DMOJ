#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MM = 3e3+5;

ll bit[MM][MM];

void add(int r, int c, int v){
    for(int i = r; i <= MM; i += i&-i){
        for(int j = c; j <= MM; j+= j&-j){
            bit[i][j] += v;
        }
    }
}

ll sum(int r, int c){
    ll res = 0;
    for(int i = r; i > 0; i-=i&-i){
        for(int j = c; j > 0; j-=j&-j){
            res += bit[i][j];
        }
    }
    return res;
}

ll sum(int r2, int c2, int r1, int c1){
    // r2, r1 inclusive
    return sum(r2, c2) - sum(r2, c1-1) - sum(r1-1, c2) + sum(r1-1, c1-1);
}

int a[MM][MM];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    int cmd; cin >> cmd;
    while(cmd != 0){
        if(cmd == 1){
            int r, c, x; cin >> r >> c >> x;
            add(r, c, -a[r][c]);

            if((r+c)&1) x = -x;
            add(r, c, x);
            a[r][c] = x;
        } else{
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            ll bot = sum(r2, c2, r1, c1);
            if((r1+c1)&1){
                cout << -bot << "\n";
            } else{
                cout << bot << "\n";
            }
        }
        cin >> cmd;
    }
}