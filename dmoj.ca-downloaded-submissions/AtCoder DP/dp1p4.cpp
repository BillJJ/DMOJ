#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5, mod = 1e4+7;

string s;
int seen[200];
int ans[MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;

    s = " " + s;

    for(int i = 1; i < s.size(); i++){
        if(seen[s[i]]){
            ans[i] = (ans[i-1]*2 - ans[seen[s[i]] - 1]) % mod;
        } else{
            ans[i] = (ans[i-1]*2+1)%mod;
        }
        seen[s[i]] = i;
    }
    cout << ans[s.size()-1];
    return 0;
}