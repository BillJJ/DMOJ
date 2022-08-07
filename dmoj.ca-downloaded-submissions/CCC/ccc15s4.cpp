#include <bits/stdc++.h>
#include <stdio.h>
void scan(int &x){ x = 0; char a; for (a = getchar_unlocked(); a <'0' or a>'9'; a = getchar_unlocked()) {} x = a-'0'; for (a = getchar_unlocked(); a >= '0' and a <= '9'; a = getchar_unlocked()) x = x*10 + a-'0';}

using namespace std;
typedef pair<int, int> pii;
#define weight first
#define dest second

struct route{
    int v, w, dmg;
    route(int v, int w, int dmg) : v(v), w(w), dmg(dmg){};
};

int dis[2005];
vector<route> edge[2005];

int main() {
    int hull, n, m; scan(hull); scan(n); scan(m);
    for(int i = 0; i < m; i++){
        int a, b, t, h; scan(a); scan(b); scan(t); scan(h);
        edge[a].push_back(route(b,t,h));
        edge[b].push_back(route(a,t,h));
    }
    int a, b; scan(a); scan(b);

    memset(dis, 0x3f, sizeof dis);
    auto compare = [](route a, route b){if(a.dmg != b.dmg) return a.dmg > b.dmg; else return a.w > b.w;};
    priority_queue<route, vector<route>, decltype(compare)> q(compare);
    q.push(route(a, 0, 0));
    while(!q.empty()) {
        route curr = q.top();
        q.pop();
        if (dis[curr.v] > curr.w) {
            dis[curr.v] = curr.w;

            for (route &r : edge[curr.v]) {
                //curr.w + r.w < dis[r.v] &&
                if (curr.dmg + r.dmg < hull) {
                    q.push(route(r.v, curr.w + r.w, curr.dmg + r.dmg));
                }
            }
        }
    }

    if(dis[b] != 1061109567){
        cout << dis[b];
    }
    else{
        cout << -1;
    }
    return 0;
}