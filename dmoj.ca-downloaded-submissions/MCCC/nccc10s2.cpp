#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5, mod=1e9+7;

int d[27], n, k;
string s[MM];

bool isbefore(char b, char a){ // b ... a
    for(int i = 1; i <= n; i++){
        for(char c : s[i]){
            if(c == b) break;
            if(c == a) return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }

    int res = 0;
    d[0] = 1;
    for(int i = 1; i < k; i++){
        d[i] = 1;
        for(int j = 0; j < i; j++){
            if(d[j]+1 > d[i] && isbefore(s[1][j], s[1][i])){
                d[i] = d[j]+1;
            }
        }
        res = max(res, d[i]);
    }
    cout << res << "\n";

    return 0;
}