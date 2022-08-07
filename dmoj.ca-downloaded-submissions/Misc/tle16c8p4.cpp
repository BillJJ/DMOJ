#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5, mod=1e9+7;

ll ans[MM], fuel[MM], diff[MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int cmd; cin >> cmd;
    if(cmd == 1){
        ll d, initial, p; cin >> d >> initial >> p;
        while(p--){
            ll q, r; cin >> q >> r;
            fuel[q] = r;
        }
        ans[0] = 1;
        diff[1]++; diff[initial+1]--;
        for(int i = 1; i <= d; i++){
            diff[i] += diff[i-1];
            diff[i] %= mod;

            ans[i] = diff[i];
            if(fuel[i]){
                diff[i+1] = (diff[i+1]+ans[i])%mod;
                diff[i+fuel[i]+1] = (diff[i+fuel[i]+1]-ans[i]+mod)%mod;
            }
        }

        cout << (ans[d])%mod;
    } else{
        int w; cin >> w;

        for(int i = 0; i < 32; i++){
            ans[i] = 32-i;
            if(!(w & (1<<(i-1)))) ans[i]--;
        }
        cout << "32 " << ans[0];
        if(ans[31]) cout << " 31\n";
        else cout << " 30\n";
        for(int i = 1; i < 32-1; i++){
            cout << i << " " << ans[i] << '\n';
        }
        if(ans[31]) cout << 31 << " " << ans[31] << '\n';
    }
    
    return 0;
}