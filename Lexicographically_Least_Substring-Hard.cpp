#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7, prime = 131;

const int MM = 1e6+5;
string s; int k;
ll pw[MM], hsh[MM];

ll get_hash(int l, int r){
    if(l == 0) return hsh[r];
    return (hsh[r] - hsh[l-1]*pw[r-l+1]%mod + mod) % mod;
}

int different(int baseL, int strL){
    int l = 0, r = k-1;
    while(l < r){
        int mid = (r-l)/2 + l;
        ll base_hash = get_hash(baseL, baseL+mid);
        ll str_hash = get_hash(strL, strL+mid);
        if(base_hash != str_hash){
            r = mid;
        } else{
            l = mid+1;
        }
    }

    return (l+r)/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s >> k;

    pw[0] = 1; hsh[0] = s[0];
    for(int i = 1; i < s.size(); i++){
        hsh[i] = (hsh[i-1]*prime + s[i]) % mod;
        pw[i] = (pw[i-1] * prime) % mod;
    }

    int kl = 0;

    for(int i = 1; i+k <= s.size(); i++){ // left is i, right is i+k-1
        int diff = different(kl, i);
        if(s[kl+diff] > s[i+diff]){
            kl = i;
        }
    }

    cout << s.substr(kl, k);

    return 0;
}