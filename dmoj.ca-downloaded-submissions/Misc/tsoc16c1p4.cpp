#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define pb push_back
using myPair = pair<int,int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int r, c;
    cin >> r;
    cin >> c;

    char map[r][c];
    for (int i=0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
        }
    }
    
    int total = 0;
    deque<int> qr;
    deque<int> qc;
    int vis[r][c] = {0};
    
    for(int i = 1; i < r-1; i++){
        for(int j = 1; j < c-1; j++){
            if(map[i][j] == 'M' && !vis[i][j]){
                total++;
                qr.pb(i);
                qc.pb(j);

                while(!qr.empty()){
                    int mr = qr.back(), mc = qc.back();
                    qr.pop_back();
                    qc.pop_back();
                    
                    vis[mr][mc] = true;

                    if(map[mr][mc + 1] != '#' && !vis[mr][mc + 1]){
                        qr.pb(mr);
                        qc.pb(mc + 1);
                    }
                    if(map[mr][mc - 1] != '#' && !vis[mr][mc - 1]){
                        qr.pb(mr);
                        qc.pb(mc - 1);
                    }
                    if(map[mr + 1][mc] != '#' && !vis[mr + 1][mc]){
                        qr.pb(mr + 1);
                        qc.pb(mc);
                    }
                    if(map[mr - 1][mc] != '#' && !vis[mr - 1][mc]){
                        qr.pb(mr - 1);
                        qc.pb(mc);
                    }
                }
            }
        }
    }
    cout << total;
    return 0;
}