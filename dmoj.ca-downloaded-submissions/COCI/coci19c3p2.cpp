#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

pii a[MM];
int p[MM], q, n;
char store[MM];
string s;

int freq[27][MM];
bool f(int stop){
    memset(freq, 0, sizeof freq);
    for(int i = 1; i <= stop; i++) store[p[i]] = s[p[i]], s[p[i]] = '?';

    for(int i = 1; i <= n; i++){
        for (int j = 0; j < 26; ++j) {
            freq[j][i] += freq[j][i-1];
        }
        if(s[i] == '?') continue;
        freq[s[i]-'a'][i]++;
    }
    bool flag = 1;

    for (int i = 1; i <=q && flag; ++i) {
        for (int j = 0; j < 26 && flag; ++j) {
            if(freq[j][a[i].second] - freq[j][a[i].first-1] > 1) flag = 0;
        }
    }

    for(int i = 1; i <= stop; i++) s[p[i]] = store[p[i]];
    return flag;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    n = s.size();
    s = "?" + s;
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    int l = 0, r = n;
    while(r-l > 5){
        int mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid+1;
    }
    for (int i = l; i <= r; ++i) {
        if(f(i)){
            cout << i <<'\n';
            break;
        }
    }

    return 0;
}