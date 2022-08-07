#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 2e5+5, MV=105;

int a[MV][MV][MV];
int dirc[6][3] = {{0, -1, 0},{0, 0, -1}, {-1, 0, 0},{1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

struct pix{
    int x, y, z, i;
};
deque<pix> q;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1, x, y, z; i <= n;i++){
        cin >> x >> y >> z;
        a[x][y][z] = i;
        q.push_back({x, y, z, i});
    }

    while(!q.empty()){
        pix u = q.front(); q.pop_front();
        for(auto[i, j, k] : dirc){
            if(0>u.x+i||u.x+i>=MV||0>u.y+j||u.y+j>=MV||0>u.z+k||u.z+k>=MV ) continue;
            if(!a[u.x+i][u.y+j][u.z+k]){
                a[u.x+i][u.y+j][u.z+k] = u.i;
                q.push_back({u.x+i, u.y+j, u.z+k, u.i});
            }
        }
    }

    while(m--){
        int x, y, z; cin >> x >> y >> z;
        cout << a[x][y][z] << "\n";
    }

    return 0;
}