#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

vector<pii> a;
priority_queue<int, vector<int>, greater<> > candy;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, t; cin >> n >> m >> t;
    for(int i = 1, p, c; i <= n; i++){
        cin >> p >> c; a.push_back({p, c});
    }

    sort(a.begin(), a.end());

    int res = 0, sum = 0;
    for(auto[p, c] : a){
        if(p*2 > m) break;

        sum += c; candy.push(c);

        int houses = (m-p*2)/t;
        while(candy.size() > houses) {
            sum -= candy.top(); candy.pop();
        }
        res = max(res, sum);
    }

    cout << res;

    return 0;
}