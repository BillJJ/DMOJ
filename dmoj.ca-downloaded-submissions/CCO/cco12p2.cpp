#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

vector<pii> edge1[20005];
vector<pii> edge2[20005];
priority_queue<pii, vector<pii>, greater<pii>> q;

int dis1[20005];
int dis2[20005];
int n;

void do_1(){
    memset(dis1, -1, sizeof dis1);
    for(pii p : edge1[1]){
        q.push(p);
    }
    dis1[1] = 0;
    while(!q.empty()){
        pii m = q.top(); q.pop();
        if(dis1[m.second] == -1){
            dis1[m.second] = m.first;
            for(pii p : edge1[m.second]){
                if(dis1[p.second] == -1){
                    q.push({p.first + m.first, p.second});
                }
            }
        }
    }
}

void do_2(){
    memset(dis2, -1, sizeof dis2);
    for(pii p : edge2[n])
        q.push(p);
    dis2[n] = 0;
    while(!q.empty()){
        pii m = q.top(); q.pop();
        if(dis2[m.second] == -1){
            dis2[m.second] = m.first;
            for(pii p : edge2[m.second]){
                if(dis2[p.second] == -1)
                    q.push({p.first + m.first, p.second});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        edge1[a].push_back({w, b});
        edge2[b].push_back({w, a});
    }
    do_1(); do_2();

    int shortest = dis1[n];
    if(dis1[n] == -1){cout << -1; return 0;}
    int second = INT_MAX;

    for(int i = 1; i <= n; i++){
        for(pii p : edge1[i]){
            int u = i, v = p.second, w = p.first;

            if(dis1[u] == -1 || dis2[v] == -1) continue;

            int path = dis1[u] + w + dis2[v];
            if(path < second && path != shortest){
                second = path;
            }
        }
    }
    if(second == INT_MAX){
        cout << -1; return 0;
    }
    cout << second;
    return 0;
}