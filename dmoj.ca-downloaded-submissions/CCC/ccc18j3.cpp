#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int in[5];
    in[0] = 0;
    for(int i = 1; i < 5; i++){
        cin >> in[i];
    }
    int dis[5][5] = {};
    
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            dis[i][j] = dis[i][j-1] + in[j];
        }
        for(int j = i - 1; j > -1; j--){
            dis[i][j] = dis[i][j+1] + in[j+1];
        }
    }
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}