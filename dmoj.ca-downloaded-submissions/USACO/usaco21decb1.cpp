#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e5+5;

string s; // g = 71, h = 72
int a[73];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n >> s;
    n = s.size();

    ll res = 0;
    for(int i = 0; i < s.size(); i++){
        ll l=i,r=i;
        while(l-1 >= 0 && s[l-1]!=s[i])l--;
        while(r+1 < n && s[r+1]!=s[i])r++;

        res += (r-i)*(i-l);
        if(i-l>=2) res += i-l-1;
        if(r-i>=2) res += r-i-1;
    }
    cout << res;
    return 0;
}