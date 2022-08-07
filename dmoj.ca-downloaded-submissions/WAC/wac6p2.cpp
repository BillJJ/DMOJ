#include <bits/stdc++.h>
using namespace std;

bitset<200005> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int state; cin >> state;
        if(state) vis[i] = 1;
    }
    if(vis.count() == 0){cout << 0 << '\n'; return 0;}
    
    for(int i = 1; vis.count() > 0; i++){
        
        if(i <= m) {
            int b;
            cin >> b;
            vis[b].flip();
        }

        if(vis.count() <= i){
            cout << i<< '\n'; return 0;
        }
    }
    return 0;
}