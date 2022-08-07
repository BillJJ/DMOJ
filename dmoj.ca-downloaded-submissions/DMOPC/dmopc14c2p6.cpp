#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int bit[MM];

void add(int i, int v){
    for(; i <= MM; i+= i&-i) bit[i] += v;
}

int sum(int i){
    int res = 0;
    for(;i > 0; i-=i&-i) res += bit[i];
    return res;
}

vector<pii> a;

struct req{
    int a, b, mass, pos, ans;
};
vector<req> query;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int a, b, mass; cin >> a >> b >> mass;
        query.push_back({a+1, b+1, mass, i, 0});
    }

    auto comp = [](req a, req b){return a.mass > b.mass;};
    sort(query.begin(), query.end(), comp);

    for(req &qu : query){
        while(!a.empty() && a.back().first >= qu.mass) {
            add(a.back().second, a.back().first);
            a.pop_back();
        }
        qu.ans = sum(qu.b) - sum(qu.a-1);
    }

    auto comp2 = [](req a, req b){return a.pos < b.pos;};
    sort(query.begin(), query.end(), comp2);
    for(req r : query){
        cout << r.ans << '\n';
    }
}