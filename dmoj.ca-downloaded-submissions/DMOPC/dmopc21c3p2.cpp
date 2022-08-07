#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

vector<ll> a;

int main()  {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll k; cin >> k;

    if(k == (ll)(1e6)*(1e6+1)/2){

        cout << 1000000 << "\n";

        for(int i = 1; i < 1e6; i++){
            cout << 0 << " ";
        }
        cout << 0 << "\n";
        return 0;
    } else{

        for(ll i = 0; i <= 1e6; i++){
            a.push_back((i*i + i)/2);
        }

        for(int x = 0; x < a.size(); x++){
            int y = lower_bound(a.begin(), a.end(), k-a[x]) - a.begin();
            if(a[y] == k-a[x]){
                if(x+y+1 > 1e6){
                    cout << -1 << '\n'; return 0;
                }

                cout << (x + y + 1) << '\n';
                for(int i = 0; i < x; i++){
                    cout << 0 << " ";
                }
                cout << "1";
                for(int i = 0; i < y; i++){

                    if(i == 0) cout << " ";

                    if(i == y-1){
                        cout << 0; break;
                    }
                    cout << 0 << " ";
                }
                cout << '\n';
                return 0;
            }
        }
        cout << -1 << '\n';
    }

    return 0;
}