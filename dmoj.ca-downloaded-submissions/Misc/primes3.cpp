#include <iostream>
#include <bits/stdc++.h>
#include <bitset>
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

int bases[] = {2,5};

bool equation2(ull x, ull s, ull n){
    for(int r = 1; r <= s; r++){
        x = mul_mod(x, x, n);
        if(x == n-1)
            return false;
    }
    return true;
}

bool miller_rabin(ull n){

    if(n <= 1) return false;
    if(n ==2||n==3) return true;
    if(!(n&1)) return false;

    ull s = -1, d = n-1;
    while(!(d & 1)) {d>>=1; s++;}

    for(int &a : bases){
        if(a > n-2) break;

        ull first = mod_exp(a, d, n);
        if(first != 1 && first != n-1 && equation2(first,s , n)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ull n; cin >> n;
        if(miller_rabin(n))
            cout << "PRIME";
        else
            cout << "NOT";

        cout << "\n";
    }
    return 0;
}