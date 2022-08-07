#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e5+5;

int a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a+1, a+n+1, greater<int>());
    for(int i = 1; i <= n; i++){
        if(a[i] < i){
            cout << i-1; return 0;
        }
    }
    cout << n;
    
    return 0;
}