#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e5+5;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    if(n == 1){cout << "1\n"; return 0;}
    else if(n == 2){cout << "-1\n"; return 0;}

    cout << "1 3 2";
    for(int i = 4; i <= n; i++){
        cout << " " << i;
    }
    cout << "\n";

    return 0;
}