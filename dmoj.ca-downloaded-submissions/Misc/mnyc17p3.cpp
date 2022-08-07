#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

const ll mod = 1e9+7, prime = 101;

string a, b;
ll hsha[MM], hshb[MM], pw[MM];

bool is_prefix(int left, int right){
    int length = right - left + 1;
    if(length > b.size()) return 0;

    ll suba = (hsha[right] - hsha[left-1]*pw[right-left+1] % mod + mod) % mod;
    return suba == hshb[length-1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> a >> b;

    pw[0] = 1;
    hsha[0] = a[0];
    for(int i = 1; i < a.size(); i++){
        hsha[i] = (hsha[i-1] * prime + a[i]) % mod;
        pw[i] = (pw[i-1] * prime) % mod;
    }
    hshb[0] = b[0];
    for(int i = 1; i < b.size(); i++){
        hshb[i] = (hshb[i-1] * prime + b[i]) % mod;
        if(!pw[i]) pw[i] = (pw[i-1] * prime) % mod;
    }

    for(int i = 0; i < a.size(); i++){
        if(is_prefix(i, a.size()-1)){
            cout << a.substr(0, i) + b; return 0;
        }
    }

    cout << a+b;

    return 0;
}