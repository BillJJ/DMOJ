#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll inv(ull A, ull M){
    ll y = 0, x = 1; ull MOD = M;
    if(M == 1)  return 0;
    while(A > 1){
        ll Q = A/M; ull temp = M;
        M = A%M; A = temp;
        temp = y; y = x-Q*y; x = temp;}
    if(x < 0) x += MOD;
    return x % MOD;
}

int main(){
    ull N, M;
    scanf("%llu %llu", &N, &M);
    printf("%lld", inv(N, M));
}