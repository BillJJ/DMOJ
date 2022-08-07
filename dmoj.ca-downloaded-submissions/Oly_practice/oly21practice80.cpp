#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 2e3+5;

vector<ll> a;

int main()  {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    for(ll i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(n/i != i)
                a.push_back(n/i);
            a.push_back(i);
        }
    }

    sort(a.begin(), a.end());
    for(ll &i : a){
        cout << i << '\n';
    }
    return 0;
}