#include <bits/stdc++.h>
#include <stdio.h>
#define BLOCKSZ (1<<16)
char _out[BLOCKSZ], *_eout=_out+BLOCKSZ, *_pout=_out;
char _buf[BLOCKSZ], *_p=_buf;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, BLOCKSZ, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define min(a,b) a<b?a:b
char _inp[BLOCKSZ], *_pinp=_inp, _;
int _ssign;

using namespace std;
typedef pair<int, int> pii;

int node[1005];
vector<pii> edge[1005];
int dis[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;

    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(w, v));
        edge[v].push_back(make_pair(w, u));
    }
    fill(begin(dis), end(dis), -1);

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(0, 1));
    // weight first, destination second
    // m.weight, m.city
    while(!q.empty()){
        pii m = q.top();
        q.pop();
        if(dis[m.second] == -1){
            dis[m.second] = m.first;
            for(pii &p : edge[m.second]){
                if(dis[p.second] == -1){
                    q.push(make_pair(p.first + m.first, p.second));
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << dis[i];
        cout << '\n';
    }

    return 0;
}