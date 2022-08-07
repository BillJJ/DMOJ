#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_composite(int n){
    int sqroot = floor(sqrt(n));
    for(int i = 3; i <= sqroot; i+=2){
        if(n%i == 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;

    if(n < 2) {cout << 2; return 0;}
    else if(n == 2){cout << 2; return 0;}

    if(!(n&1)) n++;
    while(is_composite(n)) n+= 2;
    cout << n;

    return 0;
}