#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

string s;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m, n, u, f, d;
    cin >> m >> n >> u >> f >> d >> s;
    int run = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'f') run += 2*f;
        else run += u + d;
        if(run > m){
            cout << i; break;
        }
    }

    return 0;
}