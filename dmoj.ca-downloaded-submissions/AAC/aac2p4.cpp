#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[605];
int b[605];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(begin(a), begin(a) + n, greater<int>());

        if(n == 1){cout << a[0] << '\n'; continue;}

        if(n & 1){
            for(int i = 0; i < n; i++){
                cout << a[i];
                if(i != n-1) cout << ' ';
            }
            cout << '\n';
        }
        else{
            if(a[0] == a[n-1]){cout << -1 << '\n'; continue;}
            for(int i = 0; i < n; i+= 2){
                b[i] = a[i/2];
            }
            for(int i = 1; i < n; i+= 2){
                b[i] = a[n - i/2 - 1];
            }
            for(int i = 0; i < n; i++){
                cout << b[i];
                if(i != n-1) cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}