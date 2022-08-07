#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5, MV = 1e9;

vector<pii> roomba, cord;

unordered_map<int, int> bit;
void add(int i, int v){
    for(;i <= MV; i+=i&-i) bit[i] += v;
}

int query(int i){
    int res = 0;
    for(;i > 0; i -= i&-i) res += bit[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        roomba.push_back({x, y});
    }
    for(int i = 0, x, y; i < m; i++){
        cin >> x >> y;
        cord.push_back({x, y});
    }

    sort(roomba.begin(), roomba.end(), [](pii a, pii b){return a.second > b.second;}); // greatest to least y
    sort(cord.begin(), cord.end(), [](pii a, pii b){return a.second < b.second;}); // least to greatest y

    ll res = 0;
    for(auto [x, y] : roomba){
        while(!cord.empty() && y <= cord.back().second){
            add(cord.back().first, 1);
            cord.pop_back();
        }
        res += query(x);
    }

    cout << res <<'\n';

    return 0;
}