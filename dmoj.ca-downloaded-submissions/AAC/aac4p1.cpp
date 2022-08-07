#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int MM = 1e6+5;

string s;
int a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m >> s;
    int greatest = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            cin >> a[i];
            if(a[i] >= a[greatest]) greatest = i;
        }
    }

    for(int i = greatest; i < n; i++){
        if(s[i] != '0') cout << s[i];
    }
    for(int i = 0; i < greatest; i++){
        if(s[i] != '0') cout << s[i];
    }
    cout << '\n';

    return 0;
}