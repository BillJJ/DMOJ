#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int a, b;
    int temp;

    cin >> temp;
    a += temp * 3;
    cin >> temp;
    a += temp * 2;
    cin >> temp;
    a += temp;

    cin >> temp;
    b += temp * 3;
    cin >> temp;
    b += temp * 2;
    cin >> temp;
    b += temp * 1;

    if(a > b){
        cout << "A";
    }
    else if(a < b){
        cout << "B";
    }
    else{
        cout << "T";
    }
    return 0;
}