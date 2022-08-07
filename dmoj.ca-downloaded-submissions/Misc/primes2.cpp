#include <iostream>
#include <bits/stdc++.h>
#include <bitset>
#define ull unsigned long long

using namespace std;

vector<int> prime;

bool trial_div_with_primes(ull n){
    if(n == 1) return false;
    for(int &i : prime){
        if(i > sqrt(n)) break;
        if(n == i) return true;
        if(n%i == 0) return false;
    }
    return true;
}

bitset<20000005> sieve;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    ull n, m; cin >> n >> m;

    prime.push_back(2);
    for(int i = 3; i <= sqrt(m); i+= 2){
        if(trial_div_with_primes(i)){
            prime.push_back(i);
        }
    }
    if(!trial_div_with_primes(n)){
        sieve[0] = 1;
    }

    for(int p : prime){
        for(ull i = ceil((double)n/p) * p; i <= m; i += p){
            if(i == p) continue;
            sieve[i-n] = 1;
        }
    }

    for(int i = 0; i+n < m; i++){
        if(!sieve[i]) cout << i+n << "\n";
    }
    return 0;
}