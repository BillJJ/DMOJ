#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5, mod=1e9+7;

string s[MM];
int n, k;

int score(int ans){
    int res = k;
    for(int j = 1; j <= n; j++){
        int lineans = 0;
        for(int i = 0; i < s[1].size(); i++){
            int dig = (s[j][i] == 'T');
            if((dig<<i) == ((1<<i) &ans)){
                lineans++;
            }
        }
        res = min(res, lineans);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }

    int res = 0;
    for(int i = 0; i < 1<<k; i++){
        res = max(res, score(i));
    }
    cout << res << "\n";

    return 0;
}