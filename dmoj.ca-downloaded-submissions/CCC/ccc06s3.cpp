#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define y second
#define x first

int A, B, C;
bool ccw(pii a, pii b, pii c){
    return (c.y - a.y)*(b.x-a.x) > (b.y-a.y)*(c.x-a.x);
}

bool online(pii a, pii b, pii p){
    return A*p.x + B*p.y + C == 0;
}

bool intersect(pii a, pii b, pii c, pii d){
    if(max(a.x, b.x) < min(c.x, d.x)) return 0;
    if(online(a, b, c) || online(a, b, d)) return 1;
    return ccw(a,c,d) != ccw(b,c,d) && ccw(a,b,c) != ccw(a,b,d);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    pii r, j; cin >> r.x >> r.y >> j.x >> j.y;
    A = r.y - j.y, B = j.x - r.x; C = -A*r.x - B*r.y;

    int total = 0;
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        bool block = 0;
        vector<pii> point (n);
        for(pii &p : point) cin >> p.x >> p.y;

        for(int i = 1; i < n; i++){
            if(intersect(r, j, point[i-1], point[i])) block = 1;
        }
        if(intersect(r, j, point[0], point[n-1])) block = 1;

        if(block) total++;
    }
    cout << total;
    return 0;
}