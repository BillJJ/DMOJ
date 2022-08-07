#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

map<pii, int> col; // edge : colour
pii ord[MM];
vector<int> edge[MM];

int A, B, C, D, n, m;

priority_queue<pii, vector<pii>, greater<pii>> q;
int dis[MM], dis2[MM];
bool imp(){
    for(int i = 1; i <= m; i++){
        if(ord[i].first==C&&ord[i].second==D)return 0;
    }

    memset(dis, 0x3f, sizeof dis);
    q.push({0, A});
    while(!q.empty()){
        auto[d, u] = q.top(); q.pop();
        if(d > dis[u]) continue;
        dis[u] = d;
        if(u == C || u == D) continue;
        for(int &v : edge[u]){
            if(dis[v] > d+1) q.push({d+1, v});
        }
    }

    if(dis[B] < MM){

        int u = B;
        while(u != A){
            for(int &v : edge[u]){
                if(dis[v] < dis[u]){

                    int x=u,y=v;
                    if(x>y) swap(x,y);
                    col[{x,y}] = 1;

                    u = v;
                    break;
                }
            }
        }

        return 1;
    }

    memset(dis2, 0x3f, sizeof dis2);
    q.push({0, B});
    while(!q.empty()){
        auto[d, u]= q.top();q.pop();
        if(d > dis2[u]) continue;

        dis2[u] = d;
        if(u== C || u == D) continue;
        for(int &v : edge[u]){
            if(dis2[v] > d+1) q.push({d+1, v});
        }
    }

    if(dis[C] < MM && dis2[C] < MM){
        int u = C;
        while(u != A){
            for(int &v : edge[u]){
                if(dis[v] < dis[u]){
                    int x=u,y=v;
                    if(x>y) swap(x,y);
                    col[{x,y}] = 1;

                    u = v;
                    break;
                }
            }
        }

        u = C;
        while(u != B){
            for(int &v : edge[u]){
                if(dis2[v] < dis2[u]){
                    int x=u,y=v;
                    if(x>y) swap(x,y);
                    col[{x,y}] = 1;

                    u = v;
                    break;
                }
            }
        }

        return 1;
    } else if(dis[D] < MM && dis2[D] < MM){
        int u = D;
        while(u != A){
            for(int &v : edge[u]){
                if(dis[v] < dis[u]){
                    int x=u,y=v;
                    if(x>y) swap(x,y);
                    col[{x,y}] = 1;

                    u = v;
                    break;
                }
            }
        }

        u = D;
        while(u != B){
            for(int &v : edge[u]){
                if(dis2[v] < dis2[u]){
                    int x=u,y=v;
                    if(x>y) swap(x,y);
                    col[{x,y}] = 1;

                    u = v;
                    break;
                }
            }
        }
        return 1;
    }
    return 0;
}

int main() {

    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++){
        cin >> u>>v;
        if(u > v) swap(u, v);
        ord[i]={u,v};
        edge[u].push_back(v), edge[v].push_back(u);
    }

    cin >> A >> B >> C >> D;
    if(B > A) swap(A, B);
    if(C > D) swap(C, D);
    if(!imp()){
        cout << -1; return 0;
    }

    for(int &v : edge[D]){
        int x=D,y=v;
        if(x > y) swap(x, y);
        col[{x, y}] = 1;
    }

    cout << 2 << "\n";
    for(int i = 1; i <= m; i++){
        if(col[ord[i]] == 1){
            cout << 1 << "\n";
        } else{
            cout << 2 << "\n";
        }
    }

    return 0;
}