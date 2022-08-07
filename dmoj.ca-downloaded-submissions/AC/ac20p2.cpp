#include <bits/stdc++.h>
#include <cmath>
#pragma GCC target ("avx2")
using namespace std;

typedef long long ll;

ll a[100005];

int main() {

    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) {int c; cin >> c; a[c]++;}

    for(int i = 0; i < q; i++){
        int oper, x; cin >> oper >> x;

        if(oper == 1){
            if(x & 1){
                int top = floor(x/2), bot = ceil((double)x/2);
                a[top] += a[x];
                a[bot] += a[x];
            }
            else{
                a[x/2] += 2*a[x];
            }
            a[x] = 0;
        }
        else if(oper == 2){
            cout << a[x] << '\n';
        }
    }

    return 0;
}