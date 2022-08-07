#include <bits/stdc++.h>
#include <stdio.h>
void scan(int &x){ x = 0; char a; for (a = getchar_unlocked(); a <'0' or a>'9'; a = getchar_unlocked()) {} x = a-'0'; for (a = getchar_unlocked(); a >= '0' and a <= '9'; a = getchar_unlocked()) x = x*10 + a-'0';}
using namespace std;
typedef pair<int, int> pii;
struct wall{
    int a, b, u, w;
    //corners a,b; pen u; weight w
    wall(int ia, int ib, int iw, int iu) {a = ia; b = ib;u=iu;w=iw;}
    bool operator <(const wall& x) const{
        if(a != x.a) return a < x.a;
        return b < x.b;
    }
};

vector<wall> edge;
vector<int> wallsearch[805];
vector<pii> node[105];
bitset<805> vis;

int main() {

    int n; scan(n);
    for(int i = 1; i <= n; i++){
        int e; scan(e);
        vector<int> v;
        for(int j = 0; j < e; j++){
            int corner; scan(corner); v.push_back(corner);
        }
        for(int j = 1; j < e; j++){
            int weight; scan(weight);
            if(v[j] > v[j-1]){
                edge.push_back(wall(v[j-1], v[j], weight, i));
            }
            else{
                edge.push_back(wall(v[j], v[j-1], weight, i));
            }
            wallsearch[v[j-1]].push_back(v[j]);
            wallsearch[v[j]].push_back(v[j-1]);
        }
        int weight; scan(weight);
        if(v[e-1] > v[0]){
            edge.push_back(wall(v[0], v[e-1], weight, i));
        } else{
            edge.push_back(wall(v[e-1], v[0], weight, i));
        }
        wallsearch[v[e-1]].push_back(v[0]);
        wallsearch[v[0]].push_back(v[e-1]);
    }
    sort(edge.begin(), edge.end());

    int i = 0;
    for(; i < edge.size() - 1; i++){
        if(edge[i].a == edge[i+1].a && edge[i].b == edge[i+1].b){
            node[edge[i].u].push_back(make_pair(edge[i].w, edge[i+1].u));
            node[edge[i+1].u].push_back(make_pair(edge[i].w, edge[i].u));
            i++;
        }
        else{
            node[edge[i].u].push_back(make_pair(edge[i].w, 0));
            node[0].push_back(make_pair(edge[i].w, edge[i].u));
        }
    }
    if(i == edge.size()-1) {
        node[edge[i].u].push_back(make_pair(edge[i].w, 0));
        node[0].push_back(make_pair(edge[i].w, edge[i].u));
    }
    edge.clear();

    int sum = 0, sum_indoors = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;

    for(pii &p : node[1]){
        q.push(p);
    }
    vis[1] = 1;
    while(!q.empty()){
        pii m = q.top(); q.pop();
        if(vis[m.second]) continue;
        vis[m.second] = 1;
        sum += m.first;
        for(pii &p : node[m.second]){
            if(!vis[p.second]){
                q.push(p);
            }
        }
    }

    vis.reset();
    vis[0] = 1;
    for(pii &p : node[1]){
        if(p.second != 0)
            q.push(p);
    }
    vis[1] = 1;
    while(!q.empty()){
        pii m = q.top(); q.pop();
        if(vis[m.second]) continue;
        vis[m.second] = 1;
        sum_indoors += m.first;
        for(pii &p : node[m.second]){
            if(!vis[p.second]){
                q.push(p);
            }
        }
    }
    if(vis.count() != n+1)
        sum_indoors = INT_MAX;

    cout << min(sum_indoors, sum);
    return 0;
}