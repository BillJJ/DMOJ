#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

vector<int> edge[MM];
int ind[MM];
deque<int> q;
vector<int> ans;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        edge[b].push_back(a); ind[a]++;
    }

    for (int i = 1; i <= n; ++i) {
        if(ind[i] == 0) q.push_back(i);
    }

    while(q.size()){
        int u = q.front(); q.pop_front();
        ans.push_back(u);
        for(int v : edge[u]){
            ind[v]--;
            if(ind[v] == 0) q.push_front(v);
        }
    }

    if(ans.size() == n){
        cout << n << "\n";
        for(int i : ans){
            cout << i << " 1\n";
        }
    } else{
        cout << "-1\n";
    }

    return 0;
}