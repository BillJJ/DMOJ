#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=2e5+5;

int a[MM], dis[MM];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);


    ll n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dis[1] = 1;
    int u = 1;
    while(k > 0){
        if(dis[a[u]]){
            k %= (dis[u]-dis[a[u]]+1);
            while(k--){
                u = a[u];
            }
            break;
        } else{
            k--;
            dis[a[u]] = dis[u]+1;
            u = a[u];
        }
    }

    cout << u;

    return 0;
}