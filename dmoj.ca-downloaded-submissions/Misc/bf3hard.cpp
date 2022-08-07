#include <iostream>
#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

ull mul_mod(ull a, ull b, ull m) {
    if (m == 0) return a * b;
    ull r = 0;
    while (a > 0) {
        if (a & 1)
            if((r += b) > m) r %=m;
        a >>= 1;
        if ((b <<= 1) > m) b %= m;
    }
    return r;
}

ull mod_exp(ull a, ull n, ull m) {
    ull r = 1;

    while (n > 0) {
        if (n & 1)
            r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        n >>= 1;
    }
    return r;
}

bool trial_div(ull n){
    ull sqroot = floor(sqrt(n));
    for(ull i = 3; i <= sqroot; i++){
        if(n%i == 0) return true;
    }
    return false;
}

vector<ull> prime;
bool trial_div_with_primes(ull n){
    ull sqroot = floor(sqrt(n));
    for(ull &i : prime){
        if(i > sqroot) break;
        if(n%i == 0) return true;
    }
    return false;
}

int base[] = {2};
bool fermat(ull n, ull a){
    if(mod_exp(a, n-1, n) != 1){
        return true;
    }
    else{
        return false;
    }
}

void gen_primes(){
    prime.push_back(2);
    for(int i = 3; i < 390000; i+=2){
        if(!trial_div_with_primes(i)){
            prime.push_back(i);
        }
    }
}

bool is_composite(ull n){

    for(const int &i : base){
        if(i >= n) break;
        if(fermat(n, i)){
            return true;
        }
    }

    for(ull &i : prime){
        if(n%i == 0){
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    ull n; cin >> n;
    if(n < 2) {cout << 2; return 0;}
    else if(n == 2){cout << 2; return 0;}
    else if(n == 4){cout << 5; return 0;}

    if(!(n&1)) n++;
    if(n < pow(2, 55)){
        while(trial_div(n)) n+= 2;
    }
    else{
        gen_primes();
        while(is_composite(n)) n+= 2;
    }

    cout << n;

    return 0;
}