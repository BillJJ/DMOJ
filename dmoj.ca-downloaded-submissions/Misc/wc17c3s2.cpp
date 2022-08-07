#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 3e5+5;

vector<pii> e;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int l, r;cin>> l>>r;
        e.push_back({l, r});
        e.push_back({r, -l});
    }

    sort(e.begin(), e.end());
    int cover =-1,mx = -1, ans=0;
    for(auto[x, y] : e){
        if(y < 0){
            if(-y >= cover){ans++; cover = mx;}
        } else
            mx = max(mx, y);
    }

    cout << ans;

    return 0;
}