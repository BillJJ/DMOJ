#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = (1<<20)+5;

int a[MM], b[MM];

map<int, int> c;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= (1<<n); i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a+1, a+(1<<n)+1);
    for(int i = 1; i <= (1<<n); i++){
        c[a[i]] = i;
    }
    
    for(int i = 1; i <= (1<<n); i++){
        cout << (n - floor(log2(c[b[i]]))) << " ";
    }
    
    return 0;
}