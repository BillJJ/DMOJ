#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 18, MV=1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    if(t >= 100) cout << "G";
    else if(t >= 1) cout << "L";
    else cout << "S";

    return 0;
}