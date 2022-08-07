#include <bits/stdc++.h>
using namespace std;

map<int, stack<int>> fret;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, p; cin >> n >> p;
    int total = 0;
    while(n--){
        int f, x; cin >> f >> x;
        while(!fret[f].empty() && fret[f].top() > x){
            fret[f].pop(); total++;
        }
        if(fret[f].empty() || fret[f].top() < x){
            fret[f].push(x);
            total++;
        }
    }

    cout << total;

    return 0;
}