#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e5+5;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int a, b, c; cin >> a >> b >> c;
    int x, y, z; cin >> x >> y >> z;
    cout << (x+y+z) << " " << x*a + b*y+c*z << "\n";

    return 0;
}