#include <bits/stdc++.h>
#include <cmath>
#pragma GCC target ("avx2")
using namespace std;
typedef long long ll;
#define cti(x) ((int)x - 97)

vector<int> place[26];

int main() {

    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int ns, nt; cin >> ns >> nt;
    string s, t; cin >> s >> t;

    for(int i = 0; i < ns; i++){
        place[cti(s[i])].push_back(i + 1);
    }
    ll times = 0;
    int len = 0;
    for(char c : t){
        if(place[cti(c)].size() == 0){cout << -1; return 0;}

        if(place[cti(c)].back() <= len){
            len = 0;
            times++;
        }
        for(int i = 0; i < place[cti(c)].size(); i++){
            int p = place[cti(c)][i];
            if(p > len){
                len = p;
                break;
            }
        }
    }

    cout << (ll)(times * ns) + len;

    return 0;
}