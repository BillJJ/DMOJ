#include <bits/stdc++.h>
#include <cmath>
#pragma GCC target ("avx2")
using namespace std;
typedef unsigned long long ull;
int main() {

    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;

        if(c < b) swap(c, b);
        if(c < a) swap(c, a);
        if(b < a) swap(b, a);

        long long res = (ull)c*c - (ull)a*a - (ull)b*b;

        if(res < 0) cout << 'A' << '\n';
        else if(res > 0)cout << 'O'<< '\n';
        else cout << 'R'<< '\n';

    }

    return 0;
}