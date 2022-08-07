#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_pal(int n) {
    if (n % 10 == 0) return 0;
    int r = 0;
    while (r < n) {
        r = 10 * r + n % 10;
        n /= 10;
    }
    return n == r || n == r / 10;
}

bool is_prime(int n){
    int upper = sqrt(n);

    if(n < 4) return true;

    if(!(n&1)) return false;
    for(int i = 3; i <=upper; i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    for(int i = 0; i < 5; i++){
        int l, u; cin >> l >> u;
        int total = 0;
        for(int j = l; j <= u; j++){
            if(is_pal(j) && is_prime(j)){
                total++;
            }
        }
        cout << total << "\n";
    }
    return 0;
}