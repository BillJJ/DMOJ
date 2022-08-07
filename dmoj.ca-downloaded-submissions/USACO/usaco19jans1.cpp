#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5 +5;

vector<int> edge[MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, (int)edge[i].size()+1);
    }
    cout << res;
    return 0;
}