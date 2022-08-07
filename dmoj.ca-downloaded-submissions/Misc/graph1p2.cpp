#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e2+5;

bool edge [MM][MM];
int dis[MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> edge[i][j];
        }
    }

    deque<int> q;
    q.push_back(1);
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        for(int j = 1; j <= n; j++){
            if(edge[u][j] && !dis[j]){
                dis[j] = dis[u]+1;
                q.push_back(j);
            }
        }
    }

    cout << dis[n];

    return 0;
}