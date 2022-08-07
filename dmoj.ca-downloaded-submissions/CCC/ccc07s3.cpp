#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e4+5;

vector<int> edge[MM];

int dis[MM];
int bfs(int u, int v){
    deque<int> q;
    memset(dis, 0, sizeof dis);
    q.push_back(u);
    while(!q.empty()){
        int cur = q.front(); q.pop_front();
        if(cur == v) return dis[cur];
        for(int &nxt : edge[cur]){
            if(dis[nxt]) continue;
            dis[nxt] = dis[cur]+1;
            q.push_back(nxt);
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1, a,b; i <=n;i++ ){
        cin>>a>>b;
        edge[a].push_back(b);
    }

    int u, v; cin >> u >> v;
    while(u != 0){
        int res = bfs(u, v);
        if(res){
            cout << "Yes " << res-1 << "\n";
        } else{
            cout << "No\n";
        }
        cin >> u >> v;
    }

    return 0;
}