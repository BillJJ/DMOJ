#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

const ll mod = 100000000183, prime = 1573927;

unordered_set<ll> seen;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    for(int j = 1; j <= t; j++){
        seen.clear();
        int n; cin >> n;
        ll total = 0;

        while(n--){
            cin >> s;

            ll rolling = s[0];
            bool done = 0;
            if(seen.find(rolling) == seen.end()){
                total += 1;
                done = 1;
            }
            seen.insert(rolling);

            for(int i = 1; i < s.size(); i++){
                rolling = (rolling*prime + s[i]) % mod;

                if(!done && seen.find(rolling) == seen.end()){
                    done = 1;
                    total += i+1;
                }
                seen.insert(rolling);
            }

            if(!done){
                total += s.size();
            }
        }
        cout << "Case #" << j << ": "<< total << '\n';
    }

    return 0;
}