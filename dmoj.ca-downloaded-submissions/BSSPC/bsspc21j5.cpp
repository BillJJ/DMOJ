#include <bits/stdc++.h>
using namespace std;
const int MM = 250000;

bool sieve[MM];
vector<int> primes;
int sum[MM];

void build(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int i = 2; i < 500; i++){
        if(sieve[i]) continue;
        for(int j = i*i; j < MM; j+= i)
            sieve[j] = 1;
    }

    for(int i = 2; i < MM; i++){
        if(!sieve[i]) primes.push_back(i);
    }

    for(int i = 0; i < MM-5; i++){
        if(!sieve[i]) sum[i] = i;
    }
    for(int i = 1; i < MM-5; i++){
        sum[i] += sum[i-1];
    }

}

int fk(int x, int k){
    auto p = lower_bound(primes.begin(), primes.end(), x);
    return *(p+k-1);
}

int solve(int l, int r){
    return sum[r] - sum[l-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    build();
    int q; cin >> q;
    while(q--){
        int x, k; cin >> x >> k;
        int f = fk(x, k);
        cout << f << ' ' << solve(x, f) << '\n';
    }

    return 0;
}