#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 2e3+5;
const int MV = 1e4+5;

int dp[MV];
int a[MM];

struct reqs{
    int c, l, pos;
};
vector<reqs> store;
vector<pii> out; // position:ans

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, v; cin >> n >> v;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1, c, l; i <= v; i++){
        cin >> c >> l;
        store.push_back({c, l, i});
    }

    auto comp1 = [](reqs a, reqs b){return a.l > b.l;};
    sort(store.begin(), store.end(), comp1);

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = a[i]; j < MV; j++){
            dp[j] = min(dp[j], dp[j-a[i]] + 1);
        }
        while(!store.empty() && store.back().l == i){
            reqs r = store.back(); store.pop_back();
            out.push_back({r.pos, dp[r.c]});
        }
    }
    sort(out.begin(), out.end());
    for(pii p : out){
        cout << (p.second > 1e5 ? -1 : p.second) << '\n';
    }

    return 0;
}