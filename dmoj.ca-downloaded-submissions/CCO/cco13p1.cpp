#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e4+5;

vector<ll> ans;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll x; cin >> x;
    if(x <= 1e4){
        for(ll i = 2; i < x; i++){
        vector<int> s;
        ll a = x;
        while(a){
            s.push_back(a%i);
            a /= i;
        }
        bool flag = 1;
        for(int i = 0; i <= s.size()-i-1; i++) flag &= (s[i] == s[s.size()-i-1]);
        if(flag) ans.push_back(i);
    }

    for(ll i : ans) cout << i << "\n";
        return 0;
    }
    for(ll i = 2; i < x && i*i <= x; i++){
        vector<int> s;
        ll a = x;
        while(a){
            s.push_back(a%i);
            a /= i;
        }
        bool flag = 1;
        for(int j = 0; j <= s.size()-j-1; j++) flag &= (s[j] == s[s.size()-j-1]);
        if(flag) {
            ans.push_back(i);
//            cout << i << ": ";
//            for(int j = 0; j < s.size(); j++){
//                cout << s[s.size()-1-j] << " ";
//            }
//            cout << "\n";
        }
    }

    for(ll i = 1; i*i <= x; i++){
        if((x-i)%i == 0)
            ans.push_back((x-i)/i);
    }
    sort(ans.begin(), ans.end());
    for(ll i = 0;i<ans.size(); i++) if(ans[i] != ans[i-1] && ans[i] > 1) cout << ans[i] << "\n";

    return 0;
}