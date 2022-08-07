#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;

bool is_prime(int i){
    if(i <= 1) return false;
    for(int j = 2; j*j <= i; j++){
        if(i%j == 0) return false;
    }
    return true;
}

int psa[MM];
void build(){
    for(int i = 2; i < MM; i++){
        if(is_prime(i)) psa[i] = i;
    }
    for(int i = 1; i < MM; i++) psa[i] += psa[i-1];
}

int main() {

    build();
    int t; cin >> t;while(t--){
        int a, b; cin >> a >> b;
        cout << psa[b] - psa[a-1] << '\n';
    }

    return 0;
}