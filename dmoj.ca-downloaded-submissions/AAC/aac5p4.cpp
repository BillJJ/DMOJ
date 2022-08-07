#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e6+5, mod=1e9+7;

int moves(int low, int x){ // lowerbound, x
    int n = low;
    while((int)ceil((double)n/2) & 1 && x%2==0) n++;
    while((int)ceil((double)n/2) % 2 == 0 && x&1) n++;

    return n;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    int res = n-1;
    for(int i = 1; i <= n; i++){
        int large = max(i, n-i+1) - 1;
        res = min(res, moves(large, abs(i-x)));
    }
    cout << res << "\n";

    for(int i = 1; i <= res; i++) cout << 1 << "\n";

    return 0;
}