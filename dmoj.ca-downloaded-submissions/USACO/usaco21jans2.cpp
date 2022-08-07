#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;
int psa[MM], ssa[MM], n, q;
bool stk[26];

void work(int a[], const string &s){
    memset(stk, 0, sizeof stk);

    for(int i = 1; i <= n; i++){
        int c = s[i-1]-'A';
        if(!stk[c]){
            a[i]++;
        }
        for(int j = c+1; j < 26; j++) stk[j] = 0;
        stk[c] = 1;
        a[i] += a[i-1];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q; string str;
    cin >> str;

    work(psa, str);
    reverse(str.begin(), str.end());
    work(ssa, str);
    reverse(begin(ssa)+1, begin(ssa)+1+n);

    while(q--){
        int a, b; cin >> a >> b;
        cout << psa[a-1] + ssa[b+1] << '\n';
    }
}