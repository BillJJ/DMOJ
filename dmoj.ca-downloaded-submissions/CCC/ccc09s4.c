#include <bits/stdc++.h>
#include <stdio.h>
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

using namespace std;
typedef pair<int, int> pii;

vector<pii> edge[5005];
int dis[5005];
int pencil[5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, t; scan(n); scan(t);

    while(t--){
        int u,v,w;
        scan(u); scan(v); scan(w);
        edge[u].push_back(make_pair(w, v));
        edge[v].push_back(make_pair(w, u));
    }
    t = 0;
    scan(t);
    while(t--){
        int x, y; scan(x); scan(y);
        pencil[x] = y;
    }
    int d; scan(d);

    fill(begin(dis), end(dis), -1);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(0, d));
    // weight first, destination second
    // m.weight, m.city
    int least = INT_MAX;
    while(!q.empty()){
        pii m = q.top();
        q.pop();
        if(dis[m.second] == -1){
            dis[m.second] = m.first;

            if(pencil[m.second] != 0){
                least = min(least, pencil[m.second] + dis[m.second]);
            }
            if(dis[m.second] > least) break;

            for(pii &p : edge[m.second]){
                if(dis[p.second] == -1){
                    q.push(make_pair(p.first + m.first, p.second));
                }
            }
        }
    }
    cout << least;
    return 0;
}