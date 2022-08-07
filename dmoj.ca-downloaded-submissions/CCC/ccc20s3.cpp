#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define to_int(c) ((int)c)-97
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
const ll mod = 100000000183, prime = 1573927;

string n, h; long long total = 0;

unordered_set<ll> vis;
int freq[27], nfreq[27];

bool equals(){
    int i = 27;
    while(i--){
        if(freq[i] != nfreq[i]) return false;
    }
    return true;
}

ll hah(const string &s){
    ll ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret = ret*prime + s[i];
        ret %= mod;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> h;
    if(h.length() < n.length()) {cout << 0; return 0;}

    int len = n.length();
    for(char c : n) nfreq[to_int(c)]++;
    for(int i = 0; i < len; i++){
        freq[to_int(h[i])]++;
    }
    ll strhash = hah(h.substr(0, n.length()));
    if(equals()) {
        total++;
        vis.insert(strhash);
    }

    long long power = 1;
    for (int i = 0; i < n.size(); i++)
        power = (power * prime) % mod;

    for(int i = 1; i + len <= h.length(); i++){
        freq[to_int(h[i-1])]--;
        freq[to_int(h[i+len-1])]++;

        strhash = (strhash*prime + h[i+len-1])%mod;
        strhash -= power * h[i-1] % mod;
        if(strhash < 0)
            strhash += mod;

        if(equals()){
            if(vis.find(strhash) == vis.end()){
                vis.insert(strhash);
                total++;
            }
        }
    }

    cout << total;
    return 0;
}