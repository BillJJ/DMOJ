#include <bits/stdc++.h>
#include <stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void scan(int &x){ x = 0; char a; for (a = getchar_unlocked(); a <'0' or a>'9'; a = getchar_unlocked()) {} x = a-'0'; for (a = getchar_unlocked(); a >= '0' and a <= '9'; a = getchar_unlocked()) x = x*10 + a-'0';}

using namespace std;

vector<int> v[1000005];
bitset<1000005> vis;
int n, m, exit_num;

bool bfs(){
    deque<int> q;
    q.push_back(1);
    while(!q.empty()){
        int i = q.front(); q.pop_front();
        if(i == exit_num) return true;
        for(int j : v[i]){
            if(!vis[j]){
                q.push_back(j);
                vis[j] = 1;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m; scan(n); scan(m);
    exit_num = n*m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a; scan(a);
            v[i*j].push_back(a);
        }
    }

    cout << (bfs() ? "yes" : "no");

    return 0;
}