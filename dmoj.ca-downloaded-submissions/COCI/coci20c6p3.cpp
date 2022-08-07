#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5, mod=1e9+7;

ll fact[MM];

ll inv(ll A, ll M){
    ll y = 0, x = 1; ll MOD = M;
    if(M == 1)  return 0;
    while(A > 1){
        ll Q = A/M; ll temp = M;
        M = A%M; A = temp;
        temp = y; y = x-Q*y; x = temp;}
    if(x < 0) x += MOD;
    return x % MOD;
}

//int a[MM];
//map<string, int> comp;
//void truely(){
//    fact[0] = 1;
//    for(int i = 1; i < MM; i++){
//        fact[i] = (fact[i-1]*i) % mod;
//    }
//
//    int n,k; cin >> n >> k;
//    int idx = 0;
//    for(int i = 1; i <= n; i++){
//        string s; cin >> s;
//        sort(s.begin(), s.end());
//        if(comp.find(s) == comp.end()){
//            comp[s] = ++idx;
//        }
//        a[i] = comp[s];
//    }
//
//    ll res = 0;
//    for(int vis = 0; vis < (1<<n); vis++){
//        map<int, int> f;
//        for(int j = 0; j < n; j++){
//            if(vis & (1<<j)) f[a[j+1]]++;
//        }
//
//        ll run = 0;
//        for(auto[m, v] : f){
//            if(v < 2) continue;
//            run = (fact[v]* inv(fact[v-2], mod) %mod * inv(fact[2], mod) %mod + run)%mod;
//        }
//        if(run == k)
//            res++;
//    }
//    cout << res;
//}
//

map<string, int> freq;

ll dp[2][MM], cur=0, nxt=1, tmp[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for(int i = 1; i < MM; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }

    int n,k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        sort(s.begin(), s.end());
        freq[s]++;
    }

    for(auto[shjdgbfsd, x] : freq){
        memset(tmp, 0, sizeof tmp);

        for(int i = 0; i <= x && i*(i-1)/2 <= k; i++){
            tmp[i*(i-1)/2] += fact[x]* inv(fact[x-i], mod) % mod * inv(fact[i], mod) % mod;
            tmp[i*(i-1)/2] %= mod;
        }

        for(int i = 0; i <= k; i++){
            dp[nxt][i] = 0;
            for(int j = 0; j <= i; j++){
                dp[nxt][i] = (dp[nxt][i] + dp[cur][i-j] * tmp[j]%mod) % mod;
            }
            if(dp[nxt][i] == 0) dp[nxt][i] = tmp[i];
        }
        swap(nxt, cur);
    }

    cout << dp[cur][k];

    return 0;
}