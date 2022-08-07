#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

unordered_set<string> a;

void f(string m, string s, string t){
    if(s.size() == 0 && t.size() == 0){
        a.insert(m);
        return;
    }
    if(s.size() != 0)
        f(m + s[0], s.substr(1), t);
    if(t.size() != 0)
        f(m + t[0], s, t.substr(1));
    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s >> t;
    f("", s, t);

    for(string x : a){
        cout << x << "\n";
    }
    
    return 0;
}