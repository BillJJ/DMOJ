#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, p; cin >> n;
    while(n--){
        cin >> p;
        ll l = 0, r = 1.5e9;
        while(l < r){
            ll mid = (r-l)/2+l;
            ll slices = mid*(mid+1)/2+1;
            if(slices < p){
                l = mid+1;
            } else{
                r = mid;
            }
        }
        cout << (l+r)/2 << '\n';
    }

    return 0;
}