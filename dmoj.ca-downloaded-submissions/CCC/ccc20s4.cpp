#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e6+5;

int a[MM], b[MM], c[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    for(int i = 1; i <= n; i++){
        char x = s[i-1];
        if(x == 'A') a[i]++, a[i+n]++;
        else if(x == 'B') b[i]++, b[i+n]++;
        else c[i]++, c[i+n]++;
    }

    for(int i = 1; i <= 2*n; i++){
        a[i] += a[i-1], b[i] += b[i-1], c[i] += c[i-1];
    }

    int cntA = a[n], cntB = b[n], cntC = c[n];
    int res = INT_MAX;
    for(int i = 1; i+n-1 <= 2*n; i++){ // a : b : c
        res = min(res, cntA-(a[i+cntA-1]-a[i-1]) + max(c[i+cntA-1 + cntB] - c[i+cntA-1], b[i+n-1] - b[i+cntA-1+cntB]));
    }
    for(int i = 1; i+n-1 <= 2*n; i++) // a : c : b
        res = min(res, cntA-(a[i+cntA-1]-a[i-1]) + max(b[i+cntA-1 + cntC] - b[i+cntA-1], c[i+n-1] - c[i+cntA-1 + cntC]));
    cout << res;

    return 0;
}