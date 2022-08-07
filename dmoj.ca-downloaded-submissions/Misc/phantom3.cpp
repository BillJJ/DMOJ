#include <bits/stdc++.h>
#include <stdio.h>
#define BLOCKSZ (1<<16)
#define putchar(x) putchar_unlocked(x)
char _out[BLOCKSZ], *_eout=_out+BLOCKSZ, *_pout=_out;
#define print(x) do{if(!x)putchar('0');else{for(;x;x/=10)*_p++='0'+x%10;do putchar(*--_p);while(_p!=_buf);}}while(0)
char _buf[BLOCKSZ], *_p=_buf;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, BLOCKSZ, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define min(a,b) a<b?a:b
char _inp[BLOCKSZ], *_pinp=_inp, _;
int _ssign;

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
    ull n, m; scan(n); scan(m);

    prime.push_back(2);
    for(int i = 3; i < sqrt(m); i+= 2){
        if(trial_div_with_primes(i)){
            prime.push_back(i);
        }
    }
    if(!trial_div_with_primes(n)){
        sieve[0] = 1;
    }

    for(int p : prime){
        for(ull i = ceil((double)n/p) * p; i < m; i += p){
            if(i == p) continue;
            sieve[i-n] = 1;
        }
    }

    int setbits = m - n - sieve.count();
    cout << setbits;
    return 0;
}