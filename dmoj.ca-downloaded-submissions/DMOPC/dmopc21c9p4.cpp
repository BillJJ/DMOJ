#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

set<int> h[MM], t[MM], vh, vt;

vector<pii> out;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> d;
    d.resize(n+5);
    d[0].resize(m+5); d[n+1].resize(m+5);
    for(int i =1; i <= n; i++){
        d[i].resize(m+5);

        for(int j =1; j <= m; j++){
            char c; cin >> c;
            if(c == 'H') {
                h[i].insert(j);
                d[i][j] = 1;
            }
            else {
                t[i].insert(j);
                d[i][j] = 2;
            }
        }
    }

    vector<int> vd (n+5);
    for(int i = 1; i <= n; i++){
        int heads = 0;
        for(int j = 1; j <= m; j++){
            if(d[i][j] == 1) heads++;
        }
        if(heads & 1) {
            vd[i] = 1;
            vh.insert(i);
        }
        else {
            vd[i] = 2;
            vt.insert(i);
        }
    }

    while(!vh.empty()){
        int r = *vh.begin();

        while(!h[r].empty()){
            int i = *h[r].begin();
            out.push_back({r, i});
            d[r][i] = 0;
            h[r].erase(i);

            if(d[r][i-1] == 1){
                d[r][i-1] = 2;
                h[r].erase(i-1);
                t[r].insert(i-1);
            } else if(d[r][i-1] == 2){
                d[r][i-1] = 1;
                h[r].insert(i-1);
                t[r].erase(i-1);
            }

            if(d[r][i+1] == 1){
                d[r][i+1] = 2;
                h[r].erase(i+1);
                t[r].insert(i+1);
            } else if(d[r][i+1] == 2){
                d[r][i+1] = 1;
                h[r].insert(i+1);
                t[r].erase(i+1);
            }
        }

        if(t[r].size()){
            cout << -1; return 1;
        }

        for(int j = 1; j <= m; j++){
            if(d[r-1][j] == 1) d[r-1][j] = 2;
            else if(d[r-1][j] == 2) d[r-1][j] = 1;

            if(d[r+1][j] == 1) d[r+1][j] = 2;
            else if(d[r+1][j] == 2) d[r+1][j] = 1;
        }
        swap(h[r-1], t[r-1]);
        swap(h[r+1], t[r+1]);

        vd[r] = 0;
        vh.erase(r);

        if(vd[r-1] == 1){
            vd[r-1] = 2;
            vh.erase(r-1);
            vt.insert(r-1);
        } else if(vd[r-1] == 2){
            vd[r-1] = 1;
            vh.insert(r-1);
            vt.erase(r-1);
        }

        if(vd[r+1] == 1){
            vd[r+1] = 2;
            vh.erase(r+1);
            vt.insert(r+1);
        } else if(vd[r+1] == 2){
            vd[r+1] = 1;
            vh.insert(r+1);
            vt.erase(r+1);
        }
    }
    
    if(vt.size()){
        cout << "-1\n";
    } else{
        for(pii p : out){
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}