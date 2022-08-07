#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        ll i; cin >> i;
        while(i*i*i % 1000 != 888) i++;

        cout << i << "\n";
    }

    return 0;
}