#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MM = 1e6+5;
ll bit[MM];
pll a[MM];
int n;

ll sum(int i){
    ll res = 0;
    for(; i > 0; i-=i&-i) res += bit[i];
    return res;
}

void add(int i, int v){
    for(;i < MM; i+=i&-i) bit[i] += v;
}

void compress(){
    sort(begin(a), begin(a)+n+1);
    int rank = 1;
    int previous = a[0].first;
    a[0].first = rank;
    for(int i = 0; i <= n; i++){
        if(a[i].first == previous){
            a[i].first = rank;
        }else{
            rank++;
            previous = a[i].first;
            a[i].first = rank;
        }
    }
    auto compare2 = [](pll a, pll b){return a.second < b.second;};
    sort(begin(a), begin(a)+n+1, compare2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int p; cin >> n;
    ll res = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].first; a[i].second = i;
    }
    cin >> p;
    for(int i = 1; i<=n; i++) {
        a[i].first -= p;
        a[i].first += a[i-1].first;
    }
    a[0].second = 0;
    compress();

    add(a[0].first, 1);
    for(int i = 1; i <= n; i++){
        res += sum(a[i].first);
        add(a[i].first, 1);
        // cout << res << '\n';
    }

    cout << res;

    return 0;
}