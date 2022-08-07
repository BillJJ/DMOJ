#include <bits/stdc++.h>
#pragma GCC target ("avx2")
using namespace std;

int h[100005];
int dis[100005];

int main() {

    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n, k; cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> h[i];
    memset(dis, 0x3f, sizeof dis);
    dis[0] = 0;
    for(int i = 1; i < n; i++) {
        for(int t = 1; t <= k; t++){
            if(i - t < 0) break;

            dis[i] = min(dis[i], dis[i-t] + abs(h[i-t] - h[i]));
        }
    }

    cout << dis[n-1];

    return 0;
}