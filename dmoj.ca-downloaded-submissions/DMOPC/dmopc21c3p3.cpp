#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MM = 100005;

int n, m; vector<pii> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            a.push_back({i, j});
        }
    }

    sort(a.begin(), a.end(), [](pii x, pii y){
        if(x.first + x.second != y.first+y.second) return x.first+x.second < y.first+y.second;
        if((x.first+x.second)&1) return x.first < y.first;
        return x.first > y.first;
    });

    cout << (n+1)*(m+1)-1 << '\n';
    pii last = {0,0};
    for(int i = 1, pos = n; i < a.size(); i++){
        pii cur = a[i];
        pos -= cur.first-last.first+last.second-cur.second;
        cout << pos << '\n';
        last = cur;
    }

    return 0;
}