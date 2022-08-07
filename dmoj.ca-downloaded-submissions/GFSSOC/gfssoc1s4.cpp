#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 255;

int n;
ll bit[MM][MM][MM];
int curr[MM][MM][MM];

void add(int x, int y, int z, ll p){
    for(int i = x; i <= n; i+= i&-i){
        for(int j = y; j <= n; j+= j&-j){
            for(int k = z; k <= n; k+= k&-k){
                bit[i][j][k] += p;
            }
        }
    }

}

ll sum(int x, int y, int z){
    ll res = 0;
    for(int i = x; i > 0; i-= i&-i){
        for(int j = y; j > 0; j-= j&-j){
            for(int k = z; k > 0; k-= k&-k){
                res += bit[i][j][k];
            }
        }
    }
    return res;
}

ll sum(int x1, int y1, int z1, int x2, int y2, int z2){
    return sum(x2, y2, z2) - sum(x1-1, y2, z2) - sum(x2, y1-1, z2) - sum(x2, y2, z1-1) + sum(x1-1, y1-1, z2)
    + sum(x1-1, y2, z1-1) + sum(x2, y1-1, z1-1) - sum(x1-1, y1-1, z1-1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int q; cin >> n >> q;
    ll total = 0;
    while(q--){
        char cmd; cin >> cmd;
        if(cmd == 'C'){
            int x, y, z, l; cin >> x >> y >> z >> l;
            add(x, y, z, -curr[x][y][z]);
            curr[x][y][z] = l;
            add(x, y, z, l);
        }else if(cmd == 'S'){
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            total += sum(x1, y1, z1, x2, y2, z2);
        }
    }

//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            for(int k = 1; k <= n; k++){
//                printf("i: %d j: %d k: %d = %lld\n", i, j, k, bit[i][j][k]);
//            }
//        }
//    }

    cout << total;

    return 0;
}