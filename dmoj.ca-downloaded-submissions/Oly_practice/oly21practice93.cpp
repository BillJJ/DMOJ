#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

string s[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n , l; cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        string rev = s[i];
        std::reverse(rev.begin(), rev.end());
        if(s[i] > rev){
            s[i] = rev;
        }
    }

    sort(s, s+n);
    for(string str : s){
        cout << str;
    }

    return 0;
}