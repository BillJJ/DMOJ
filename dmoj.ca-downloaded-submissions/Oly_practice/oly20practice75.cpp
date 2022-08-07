#include <bits/stdc++.h>

using namespace std;

const int MM = 1e5+5;

bool a[MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    while(m--){
        int l, r; cin >> l >> r;
        a[l] ^= 1;
        a[r+1] ^= 1;
    }

    int res = 0;
    for(int i = 1 ; i <= n; i++){
        a[i] ^= a[i-1];
        if(a[i]) res++;
    }
    cout << res;
    
    return 0;
}