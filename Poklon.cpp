#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 1e5+5;
const int MV = 1e6;

vector<pii> a;
int d[MM];
int p[MM];

pii bit[MV+5]; // max val : pos of that val

void add(int i, int length, int pos){
    i = MV - i; // invert big and small (if x > y then now y > x) & one index
    for(; i <= MV; i+= i & -i){
        if(bit[i].first < length){
            bit[i] = {length, pos};
        }
    }
}

pii query(int i){ // returns max length less than
    i = MV - i;
    pii res ={0,-1};
    for(;i > 0; i-=i&-i){
        if(bit[i].first > res.first){
            res = bit[i];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        a.push_back({x, y});
    }
    auto comp = [](pii x, pii y){if(x.first == y.first) return x.second > y.second; return x.first < y.first;};
    sort(a.begin(), a.end(), comp);

    memset(p, -1, sizeof p);
    int maxd = 0;
    for(int i = 0; i < n; i++){
        pii res = query(a[i].second);
        d[i] = res.first+1;
        p[i] = res.second;

        add(a[i].second, d[i], i);
        if(d[i] > d[maxd]) maxd = i;
    }

    cout << d[maxd] << '\n';
    while(maxd >= 0){
        cout << a[maxd].first << " " << a[maxd].second << "\n";
        maxd = p[maxd];
    }

    return 0;
}