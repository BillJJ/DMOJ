#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 5e5+5;

//const ll mod = 11258999068423, prime = 131;

int r[MM];

map<int, int> c;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> r[i];
    for(int i = 1, x; i <= m; i++) {
        cin >> x;
        if(x == -1) continue;
        c[i-x]++;
    }

    ll total = 0;
    for(int i = 1; i <= n; i++){
        if(r[i] == -1) continue;

        if(c[i-r[i]] > 0){
            c[i-r[i]]--;
            total++;
        }
    }

    cout << total << '\n';

    return 0;
}