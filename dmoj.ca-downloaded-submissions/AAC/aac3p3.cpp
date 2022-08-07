#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

//const ll mod = 11258999068423, prime = 131;

int a[MM];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(begin(a), begin(a)+n);

    if(n & 1){
        for(int i = 0; i < n/2; i++){
            cout << a[i] << " " << a[i+n/2+1] << " ";
        }
        cout << a[n/2] << '\n';
        for(int i = 0; i < n/2; i++){
            cout << "BS";
        }
        cout << "E\n";
    } else{
        for(int i = 0; i < n/2; i++){
            cout << a[i] << " " << a[i+n/2] << (i == n/2-1 ? "" : " ");
        }
        cout << '\n';
        for(int i = 0; i < n/2; i++){
            cout << "BS";
        }
        cout << '\n';
    }

    return 0;
}