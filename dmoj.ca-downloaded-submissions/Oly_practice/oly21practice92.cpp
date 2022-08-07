#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

ll flatten(ll n, ll start, ll k){
    string s = to_string(n);
    string res = s.substr(0, start);
    int idx = 0;

    int freq[10] = {};
    for(int i = 0; i < start; i++){
        freq[s[i]-'0']++;
        if(freq[idx] == k) idx++;
    }

    for(int i = start; i < s.size(); i++){
        while(freq[idx] == k) idx++;
        res += (idx+'0');
        freq[idx]++;
    }
    return stoll(res);
}

ll go(ll n, ll k){
    int freq[10] = {};
    string s = to_string(n);

    ll res = 0;

    for(int i = 0; i < s.size(); i++){
        if(freq[s[i]-'0'] == k){
            if(i == s.size()-1){
                n++;
                n = go(n, k); break;
            }

            n += pow(10, (s.size() - i - 1));
            res += n%(ll)(pow(10, (s.size() - i - 1)));
            ll temp = n;
            for(int j = 1; j < (s.size() - i); j++) temp /= 10;
            n = go(temp, k)*pow(10, (s.size() - i - 1)) + res;
            break;
        } else freq[s[i]-'0']++;
    }
    return n;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k; cin >> n >> k;
    if(k == 1 && n > 9876543210) {cout << -1; return 0;}

    ll ori = n;

    n = go(n, k);
    string nw = to_string(n), old = to_string(ori);
    if(nw.size() != old.size()){
        n = flatten(n, 1, k);
    } else{
        for(int i = 0; i < nw.size(); i++){
            if(nw[i] != old[i]){
                n = flatten(n, i+1, k);
                break;
            }
        }
    }
    if(n == 1023456789){
        cout << ori << " " << k << "\n";
    }
    cout << n;

    return 0;
}