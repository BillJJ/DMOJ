#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

bitset<100001> gate;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int num_gates, planes;
    cin >> num_gates >> planes;
    gate.reset(); 
    gate.flip();
    int total = 0;
    for(int i = 0; i < planes; i++){
        int p; cin >> p;
        p++;
        int place = gate._Find_next(gate.size() - p);
        if(place < gate.size()){
            gate[place] = false;
            total++;
        }
        else{
            cout << total; return 0;
        }
    }
    cout << total;
    return 0;
}