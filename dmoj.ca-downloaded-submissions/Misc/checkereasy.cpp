#include <iostream>
typedef long long ll;
using namespace std;

const int MM = 3e3+5;

struct BIT{
    ll bit[MM][MM];
    void add(int r, int c, int v){
        for(int i = r; i <= MM; i+= i&-i){
            for(int j = c; j <= MM; j+=j&-j){
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
};

BIT odd, even;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    int r, c, x; cin >> r >> c >> x;
    while(r != 0){
        if((r+c)&1) odd.add(r, c, x);
        else even.add(r, c, x);
        cin >> r >> c >> x;
    }
    
    int r1 = 1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    while(r1 != 0){
        ll os = odd.sum(r2, c2, r1, c1);
        ll es = even.sum(r2, c2, r1, c1);
        if((r1+c1)&1) cout << os-es << "\n";
        else cout << es-os << "\n";
        cin >> r1 >> c1 >> r2 >> c2;
    }
}