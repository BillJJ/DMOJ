#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 3e3+5;

int a[MM][MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }

    int cur = 1, next = 2;
    for(; next <= k; cur = next, next = cur*1.5){
        int d = next-cur;
        for(int i = 1; i <= n-next+1; i++){
            for(int j = 1; j <= i; j++){
                a[i][j] = max({a[i][j], a[i+d][j], a[i+d][j+d]});
            }
        }

//         for(int i = 1; i <= n-next+1; i++){
//             for(int j = 1; j <= i; j++){
//                 cout << a[i][j] << " ";
//             }
//             cout << "\n";
//         }
//         cout << "\n";
    }

    int d = k-cur;
    ll total = 0;
    for(int i = 1; i <= n-k+1; i++){
        for(int j = 1; j <= i; j++){
            total += max({a[i][j], a[i+d][j], a[i+d][j+d]});
        }
    }

    cout << total;

    return 0;
}