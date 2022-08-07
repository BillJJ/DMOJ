#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int a = 0, b = 0;
    int v; cin >> v;
    string s; cin >> s;
    for(char c : s){
        if(c == 'A'){
            a++;
        }
        else{
            b++;
        }
    }
    if(a > b){
        cout << "A";
    }
    else if (a < b){
        cout << "B";
    }
    else{
        cout << "Tie";
    }
    return 0;
}