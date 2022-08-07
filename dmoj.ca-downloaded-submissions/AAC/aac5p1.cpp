#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e2+5, mod=1e9+7;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int o=0,e=0;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        if(x&1) o++;
        else e++;
    }

    cout << (e/2 + o/2) << "\n";

    return 0;
}