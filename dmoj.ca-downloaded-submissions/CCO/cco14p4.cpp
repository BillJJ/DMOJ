#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e4+5;

vector<pii> a;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, p, f=0; cin >> n >> p;
    for(int i = 1; i <= n; i++){
        int x, y;cin>>x>>y;
        if(i == p) {f=x; continue;}
        if(y > x) continue;
        a.push_back({y, x});
    }

    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        if(f >= a[i].first){
            f += -a[i].first + a[i].second;
        } else{
            cout << f <<  "\n"  << i+1 << "\n";
            return 0;
        }
    }

    cout << f << "\n" << a.size()+1 << "\n";

    return 0;
}