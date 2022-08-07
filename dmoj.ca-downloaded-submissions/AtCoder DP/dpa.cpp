#include <bits/stdc++.h>
#pragma GCC target ("avx2")
using namespace std;

int h[100005];
int dis[100005];

int main() {

    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n; cin >> n;

    for(int i = 0; i < n; i++) cin >> h[i];

    dis[1] = abs(h[1] - h[0]);

    for(int i = 2; i < n; i++) {
        int one = abs(h[i] - h[i-1]);
        int two = abs(h[i] - h[i-2]);
        dis[i] = min(one + dis[i-1], two + dis[i-2]);
    }

    cout << dis[n-1];

    return 0;
}