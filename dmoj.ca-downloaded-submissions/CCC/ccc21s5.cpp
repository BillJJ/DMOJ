#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 150005;
struct req {
    int l, r, z;
};

vector<req> reqs;
int a[MM];
int n;
int seg[MM*2];
int diff[17][MM]; // don't know lazy prop so just using diff array ;-;

void build(){
    for(int i = 0; i < n; i++){
        seg[i+n] = a[i+1];
    }
    for(int i = n-1; i; i--){
        seg[i] = gcd(seg[i*2], seg[i*2+1]);
    }
}

int query(int l, int r){
    r++;
    int res = 720720; // divisible by 1 - 16
    for(l += n, r += n; l < r; l /= 2, r/=2 ){
        if(l&1) res = gcd(res, seg[l++]);
        if(r&1) res = gcd(res, seg[--r]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    fill(begin(a), begin(a)+n+1, 1);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        reqs.push_back({x, y, z});
        diff[z][x]++; diff[z][y+1]--;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 16; j++){
            diff[j][i] += diff[j][i-1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int z = 1; z <= 16; z++){
            if(diff[z][i])
                a[i] = a[i] * z / gcd(a[i], z);
        }
    }

    build();

    for (req r : reqs) {
        if (query(r.l-1, r.r-1) != r.z) {
            cout << "Impossible"; return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}