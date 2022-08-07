#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*1000005;
const int sqrtMAXN = (int)sqrt(MAXN);

bool sieve[MAXN];
void gen_sieve(){
    sieve[0] = sieve[1] = 1;

    for(int i = 2; i <= sqrtMAXN; i++){
        if(sieve[i]) continue;

        for(int j = i*i; j < MAXN; j+= i){
            sieve[j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n, t; cin >> t;
    gen_sieve();
    while(t--){
        cin >> n;

        for(int i = 2; i <= n; i++){
            if(sieve[i]) continue;
            if(2*n - i < 2 || 2*n - i > MAXN) continue;

            if(!sieve[2*n - i]){
                cout << i << ' '<<  2*n - i << '\n';
                break;
            }
        }
    }

    return 0;
}