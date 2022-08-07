#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e3+5;

deque<int> a[MM], b[MM];
int ans[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n >> t;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i].push_back(x);
    }

    while(t--){
        for(int i = 1; i <= n; i++){
            if(!a[i].empty()){
                ans[i] = a[i].front();
                b[a[i].front()].push_back(i);
                a[i].pop_front();
            }
        }
        for(int i = 1; i <= n; i++){
            while(!b[i].empty()){
                a[i].push_back(b[i].front());
                b[i].pop_front();
            }
        }
    }

    cout << ans[1];
    for(int i = 2; i <= n; i++){
        cout << " " << ans[i];
    }cout << "\n";

    return 0;
}