#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        unsigned long long x; cin >>x;
        int total = 0;
        while(x > 3){
            while(!(x & 1)){
                x = x>>1;
                total++;
            }
            if(x <= 3){
                break;
            }
            if(x & 2){
                x++;
                total++;
            }else{
                x--;
                total++;
            }
        }
        switch(x){
            case 3:
                total++;
            case 2:
                total++;
            case 1:
                total++;
            default:
                cout << total << "\n";
        }
    }
    return 0;
}