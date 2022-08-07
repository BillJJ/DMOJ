#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 5e4+5, LOG = 17;
int tmax[LOG][MM], tmin[LOG][MM];
int n;

int query_max(int l, int r){
    int len = log2(r-l+1);
    return max(tmax[len][l], tmax[len][r-(1<<len)+1]);
}

int query_min(int l, int r){
    int len = log2(r-l+1);
    return min(tmin[len][l], tmin[len][r-(1<<len)+1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        tmin[0][i] = a;
        tmax[0][i] = a;
    }

    for(int j = 1; j < LOG; j++){
        for(int i = 0; i+(1<<j-1) < n; i++){
            tmax[j][i] = max(tmax[j-1][i], tmax[j-1][i+(1<<j-1)]);
            tmin[j][i] = min(tmin[j-1][i], tmin[j-1][i+(1<<j-1)]);
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--; b--;
        cout << (query_max(a, b) - query_min(a, b)) << "\n";
    }

    return 0;
}