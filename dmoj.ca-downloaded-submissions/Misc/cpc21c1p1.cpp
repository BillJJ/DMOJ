#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
const int MM = 8388608 + 5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        
        ll g = gcd(a, b);
         a /= g;
         b /= g;

        ll fac = b;
        ll five = 0, two = 0;
        while(fac % 5 == 0){
            five++;
            fac /= 5;
        }
        while(fac % 2 == 0){
            two++;
            fac /= 2;
        }
        if(fac != 1){
            cout << -1 << '\n';
            continue;
        }

        cout << max(five, two) << '\n';
    }

    return 0;
}