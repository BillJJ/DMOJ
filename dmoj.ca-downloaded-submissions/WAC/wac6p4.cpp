#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll over_mod(ll i){
    if(i >= 998244353){
        return i % 998244353;
    }
    return i;
}

ll fac(ll i){
    if(i <= 1) return 1;
    ll ret = 1;
    while(i > 0){
        ret = over_mod(ret * i);
        i--;
    }
    return ret;
}

ll choose3(ll n){
    if(n < 10)
        return over_mod(fac(n) / (6 * fac(n - 3)));
    else
        return over_mod(n * (n-1) * (n-2) / 6);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n, k; cin >> n >> k;

    string r;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        switch(c){
            case 'W':
            case 'A':
            case 'C':
                r += c;
                break;
        }
    }

    ll w=0, a=0, c=0, wa=0, wc=0, aw=0, ac=0, cw=0, ca=0, wac=0, wca=0, awc=0, acw=0, cwa=0, caw=0;

    for (int i = 0; i < r.size(); i++) {
        if (r[i] == 'W') {
            w++;
            aw = over_mod(aw + a);
            cw = over_mod(cw + c);
            acw = over_mod(acw + ac);
            caw = over_mod(caw + ca);
        } else if (r[i] == 'A') {
            a++;
            wa = over_mod(wa + w);
            ca = over_mod(ca + c);
            wca = over_mod(wca + wc);
            cwa = over_mod(cwa + cw);
        } else if (r[i] == 'C') {
            c++;
            wc = over_mod(wc + w);
            ac = over_mod(ac + a);
            wac = over_mod(wac + wa);
            awc = over_mod(awc + aw);
        }
    }

    ll total = 0;
    total = over_mod(total + wac * choose3(k+2));
    total = over_mod(total + caw * choose3(k));
    total += over_mod(over_mod(cwa + acw + awc + wca) * choose3(k+1));

    cout << over_mod(total) << '\n';
    return 0;
}