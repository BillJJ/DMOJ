#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define temp first
#define expire second

vector<pii> v;
auto comp = [](pii a, pii b){return a.second > b.second;};
priority_queue<pii, vector<pii>, decltype(comp) > q (comp);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int x, n; cin >> x >> n;
    int maxt = 0;
    for(int i = 0 ; i < n; i++) {
        int a, b;
        cin >> a >> b;
        maxt = max(a, maxt);
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int total = 0;
    int t = 0;
    int soup = 0;
    while(soup < v.size() && v[soup].temp <= x){
        q.push(v[soup]);
        soup++;
    }

    while(soup < v.size() || !q.empty()){
        while(!q.empty()){
            pii p = q.top(); q.pop();

            if(t > p.expire) continue;

            total++; t++;

            while(soup < v.size() && v[soup].temp <= t + x){
                q.push(v[soup]);
                soup++;
            }
        }

        if(soup < v.size()){
           t += v[soup].temp - t - x;
           q.push(v[soup]);
           soup++;
        }
    }

    cout << total;

    return 0;
}