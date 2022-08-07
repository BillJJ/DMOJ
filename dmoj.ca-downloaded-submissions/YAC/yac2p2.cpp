#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int f[MM], a[MM];

signed main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    int m = ceil((double)n/2)-1;

    if(n & 1){
        for(int i = n; i-1 >= m; i--){
            cout << "? 1 " << i << "\n";
            cin >> f[i];
        }
        for(int i = n-m; i>1; i--){
            cout << "? " << i << " " << n << "\n";
            cin >> f[i-1];
        }

        for(int i = n; i > m; i--){
            a[i] = f[i]^f[i-1];
        }
        a[m+1] = f[n]^f[m+1]^f[m];
        for(int i = m; i > 1; i--){
            a[i] = f[i]^f[i-1];
        }
        a[1] = f[n]^f[1];
    } else{
        for(int i = n; i >= m+1; i--){
            cout << "? 1 " << i << "\n";
            cin >> f[i];
        }
        for(int i = m+1; i > 1; i--){
            cout << "? " << i << " " << n << "\n";
            cin >> f[i-1];
        }
        for(int i = n; i > m+1; i--){
            a[i] = f[i]^f[i-1];
        }
        a[m+1] = f[m+1]^f[m]^f[n];
        for(int i = m; i > 1; i--){
            a[i] = f[i]^f[i-1];
        }
        a[1] = f[1]^f[n];
    }

    cout << "! " << a[1] << " ";
    for(int i = 2; i <= n; i++){
        cout << a[i] << " \n"[i == n];
    }
    
    return 0;
}