#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

map<pii, int> dp;

int qry(int r, int c){
    if(dp[{r, c}]) return dp[{r, c}];
    cout << "? " << r << " " << c << "\n";
    int x; cin >> x;
    return dp[{r, c}] = x;
}

signed main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);

    int r, c, k; cin >> r >> c >> k;
    int lx = 1, hx = r, ly = 1, hy = c;
    while(lx < hx || ly < hy){
        int xmid = (lx+hx)/2, ymid=(ly+hy)/2;
        if(lx < hx){
            if(qry(xmid, ymid) < qry(xmid+1, ymid)) hx = xmid;
            else lx = xmid+1;
        }
        if(ly < hy){
            if(qry(xmid, ymid) < qry(xmid, ymid+1)) hy = ymid;
            else ly = ymid+1;
        }
    }

    int ans = qry((lx+hx)/2, (ly+hy)/2);
    cout << "! " << ans;

    return 0;
}