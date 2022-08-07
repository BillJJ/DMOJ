#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

vector<int> a[MM];
int b[MM];
int bit[MM];
priority_queue<int> q;

void add(int i, int v){
    for(; i < MM; i+=i&-i) bit[i] += v;
}

int query(int i){
    int res = 0;
    for(; i > 0; i-=i&-i) res += bit[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i=1, x; i<=n ;i++) {
        cin >> x;
        a[x].push_back(i);
    }

    for(int i = n; i >= 1; i--){
        if(q.empty() && a[i].empty()){cout << -1; return 0;}

        for(int &x:a[i]) q.push(x);
        b[i] = q.top(); q.pop();
    }

    ll total = 0;
    for(int i = 1; i <= n; i++){
        total += query(n)-query(b[i]);
        add(b[i], 1);
    }
    cout << total;

    return 0;
}