#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1.6e7+5;

vector<bool> vis;
int n, m, exit_num;

int q[MM], idx=0;
int freq[MM], v[MM];
pii p[MM]; // [start, end) of nums for idx

bool bfs(){
    q[++idx] = 1;
    while(idx){
        int i = q[idx--];
        if(i == exit_num) return true;
        for(int j = p[i].first; j < p[i].second; j++){
            if(!vis[v[j]]){
                q[++idx] = v[j];
                vis[v[j]] = 1;
            }
        }
    }
    return false;
}

bool can_escape(int M, int N, vector<vector<int>> vvi){
    n = M, m = N;
    exit_num = n*m;
    vis.resize(n*m+5);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            freq[i*j]++;
        }
    }

    int idx = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(p[i*j].first) continue;

            p[i*j].first = idx;
            p[i*j].second = idx;
            idx += freq[i*j];
        }
    }
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; ++j) {
            v[p[i*j].second++] = vvi[i][j];
        }
    }

    return bfs();
}

//int main() {
//    ios_base::sync_with_stdio(0);
//
//    cout << can_escape(3, 4, {{0, 0, 0, 0, 0},
//                              {0, 3, 10, 8, 1},
//                              {0, 1, 11, 12, 12},
//                              {0, 6, 2, 3, 9}});
//
//    return 0;
//}