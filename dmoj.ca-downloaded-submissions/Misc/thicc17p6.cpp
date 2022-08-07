#include <bits/stdc++.h>
#include <stdio.h>

void scan(int &x){ x = 0; char a; for (a = getchar_unlocked(); a <'0' or a>'9'; a = getchar_unlocked()) {} x = a-'0'; for (a = getchar_unlocked(); a >= '0' and a <= '9'; a = getchar_unlocked()) x = x*10 + a-'0';}
template<typename T, typename...A>void scan(T& f, A&...a) { scan(f); scan(a...); }

using namespace std;
typedef pair<int, int> pii;
#define w first
#define v second

vector<pii> edge[200001];
int dis1[200001];
int dis2[200001];

int main() {
    ios_base::sync_with_stdio(0);
    int n, t, tree_total = 0;
    scan(n,t);
    for(int i = 1; i < n; i++){
        int a, b, c; scan(a, b, c);
        tree_total += 2*c;
        edge[a].push_back(pii(c, b));
        edge[b].push_back(pii(c, a));
    }

    int farest = 1;
    deque<int> q;
    for(int i = 0; i < 2; i++) {
        memset(dis1, -1, sizeof(dis1));
        q.clear();
        dis1[farest] = 0;
        q.push_back(farest);
        while (!q.empty()) {
            int m = q.front();
            q.pop_front();
            if (dis1[m] > dis1[farest]) farest = m;
            for (pii &p : edge[m]) {
                if (dis1[p.v] == -1) {
                    dis1[p.v] = dis1[m] + p.w;
                    q.push_back(p.v);
                }
            }
        }
    }
    int farthest = farest;
    memset(dis2, -1, sizeof(dis2));
    q.clear();
    dis2[farthest] = 0;
    q.push_back(farthest);
    while (!q.empty()) {
        int m = q.front();
        q.pop_front();
        if (dis2[m] > dis2[farthest]) farthest = m;
        for (pii &p : edge[m]) {
            if (dis2[p.v] == -1) {
                dis2[p.v] = dis2[m] + p.w;
                q.push_back(p.v);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(edge[i].size() != t) continue;
        cout << i << ' ' << (tree_total - max(dis1[i], dis2[i])) << '\n';
    }

    return 0;
}