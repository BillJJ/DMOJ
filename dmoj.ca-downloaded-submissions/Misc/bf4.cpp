#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e5+5;

const ll mod = 1125899839733759, prime = 101;

string s, t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> s >> t;

    ll t_hash = 0;
    ll roll = 0;
    ll pw = 1;
    for(int i = 0; i < t.size(); i++){
        t_hash = (t_hash*prime + t[i]) % mod;
        roll = (roll * prime + s[i]) % mod;
        pw = (pw * prime) % mod;
    }
    if(roll == t_hash){
        cout << 0; return 0;
    }
    for(int i =t.size(); i < s.size(); i++){
        roll = (roll*prime + s[i]) % mod;
        roll = (roll - s[i-t.size()]*pw%mod + mod) % mod;
        if(roll == t_hash){
            cout << i-t.size()+1; return 0;
        }
    }
    cout << -1;

    return 0;
}