#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

int f[105] = {}, wait[105] = {};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int m; cin >> m;
    int time = 0;
    char c; int x; cin >> c >> x;
    for(int i = 0; i < m; i++){
        switch(c){
            case 'W':
                time += x;
                break;
            case 'R':
                wait[x] = time;
                break;
            case 'S':
                f[x] += time - wait[x];
                wait[x] = 0;
        }
        if(i == m-1) break;
        char previous = c;
        cin >> c >> x;
        if(c != 'W' && previous != 'W') time++;
    }
    for(int i = 0; i < 105; i++){
        if(wait[i])
            cout << i << " -1 \n";
        else if(f[i])
            cout << i << " " << f[i] << "\n";
        
    }
    return 0;
}