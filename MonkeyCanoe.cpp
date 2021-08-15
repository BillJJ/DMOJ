#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e3+5;

#define su(x) do{while((x=getchar_unlocked())<48); for(x-=48; 48<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar_unlocked())<45); _sign=x==45; if(_sign) while((x=getchar_unlocked())<48); for(x-=48; 48<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar_unlocked())<33);}while(0)
char _; bool _sign;

char grid[MM][MM];
vector<pii> edge[MM*MM];

priority_queue<pii, vector<pii>, greater<>> q; // weight, destination
int dis[MM*MM]; // max length allowed

int main(){
    int n, m; su(n); su(m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sc(grid[i][j]);
        }
    }

    // id = (i-1)*m + j
    // build rows first
    for(int i = 1; i <= n; i++){
        int previous = 0;
        for(int j = 1; j <= m; j++){
            if(grid[i][j] == '#'){
                if(previous != 0){
                    edge[(i-1)*m+j].push_back({(j - previous-1) == 0 ? INT_MAX : (j - previous-1), (i-1)*m+previous});
                    edge[(i-1)*m+previous].push_back({(j - previous-1) == 0 ? INT_MAX : (j - previous-1), (i-1)*m+j});
                }
                previous = j;
            }
        }
    }
    // build the cols
    for(int j = 1; j <= m; j++){
        int previous = 0;
        for(int i = 1; i <= n; i++){
            if(grid[i][j] == '#'){
                if(previous != 0){
                    edge[(i-1)*m+j].push_back({(i - previous-1) == 0 ? INT_MAX : (i - previous-1), (previous-1)*m+j});
                    edge[(previous-1)*m+j].push_back({(i - previous-1) == 0 ? INT_MAX : (i - previous-1), (i-1)*m+j});
                }
                previous = i;
            }
        }
    }

    // mst with prim's
    for(int j = 1; j <= m; j++){
        if(grid[1][j] == '#'){
            q.push({INT_MAX, j});
            dis[j] = INT_MAX;
        }
    }
    while(!q.empty()){
        pii ppp = q.top(); q.pop();
        int length = ppp.first, cur = ppp.second;
        if(dis[cur] > length) continue;

        for(pii p: edge[cur]){
            if(dis[p.second] < min(length, p.first)){
                q.push({min(length, p.first), p.second});
                dis[p.second] = min(length, p.first);
            }
        }
    }

    for(int j = 1; j <= m; j++){
        if(grid[n][j] == '.' || dis[(n-1)*m+j] == 0){
            printf("%d", -1);
        } else if(dis[(n-1)*m+j] == INT_MAX){
            printf("%d", 0);
        } else{
            printf("%d", dis[(n-1)*m+j]);
        }
        if(j != m) printf(" ");
    }
    cout << "\n";
    return 0;
}
