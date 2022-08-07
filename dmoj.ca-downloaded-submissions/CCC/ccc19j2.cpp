#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int l; cin >> l;
    for(int i = 0; i < l; i++){
        int n; cin >> n;
        char c; cin >> c;
        cout << string(n, c) << "\n";
    }

    return 0;
}