#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MM = 3e3+5;

int e[MM];
int spot[MM], num[MM], temp[MM]; // number at spot i, the spot of # i

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        spot[i] = e[i] = num[i] = i;
    }

    while(q--){
        char cmd; cin >> cmd;
        if(cmd == 'B'){
            int x, y; cin >> x >> y;
            swap(spot[x], spot[y]);
            swap(num[spot[x]], num[spot[y]]);
        } else if(cmd == 'E'){
            int x, y; cin >> x >> y;
            swap(e[x], e[y]);
        } else{
            for(int i = 1, x; i <= n; i++){
                cin >> x;
                temp[num[e[i]]] = x;
            }
            for(int i = 1; i < n; i++){
                cout << temp[i] << " ";
            }
            cout << temp[n] << '\n';
        }
    }

    return 0;
}