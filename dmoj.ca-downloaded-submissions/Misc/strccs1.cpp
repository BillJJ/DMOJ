#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << (a*b*a - a*b*b)%(100000-4) << '\n';
    }

}