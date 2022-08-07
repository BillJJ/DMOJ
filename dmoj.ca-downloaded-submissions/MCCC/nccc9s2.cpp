#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n >> s;
    ll res = 0, next = 0;
    if(s[0] == 'I') next = 2;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'I'){
            res += abs(i-next); next+=2;
        }
    }

    cout << res << '\n';

    return 0;
}