#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;

ll h[MM];
int a[MM];
deque<int> q; // index element

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    q.push_back(0);
    a[0] = -1;

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i] = x;

        while(x < a[q.back()]){
            int index = q.back(); q.pop_back();
            h[a[index]] += (ll)(index-q.back())*(i-index);
        }
        q.push_back(i);
    }
    while(q.size() > 1){
        int index = q.back(); q.pop_back();
        h[a[index]] += (ll)(index - q.back()) * (n+1-index);
    }

    for(int i = 1; i <= MM; i++){
        h[i] += h[i-1];
    }

    while(k--){
        int x, y; cin >> x >> y;
        cout << (h[y] - h[x-1]) << '\n';
    }

    return 0;
}