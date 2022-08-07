#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 4e3+5;

ll psa[MM][MM];

unordered_map<int, int> comp, uc;
struct rec{
    int x1, y1, x2, y2, tint;
} a[MM];
vector<int> nums;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);

    int n, t; cin >> n >> t;
    for(int i = 1; i <= n; i++){
        int x1, y1, x2, y2, tint; cin >> x1 >> y1 >> x2 >> y2 >> tint;
        a[i] = {x1, y1, x2, y2, tint};
        nums.push_back(x1), nums.push_back(x2),nums.push_back(y1),nums.push_back(y2);
    }

    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        comp[nums[i]] = i+1;
        uc[i+1] = nums[i];
    }

    for(int i = 1; i <= n; i++){
        auto[x1, y1, x2, y2, tint] = a[i];
        x1 = comp[x1], y1=comp[y1], x2=comp[x2], y2=comp[y2];
        psa[x1][y1] += tint, psa[x2][y1]-=tint,psa[x1][y2]-=tint,psa[x2][y2]+=tint;
    }

    ll res = 0;
    for(int i = 1; i < MM-1; i++){
        for(int j = 1; j < MM-1; j++){
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
            if(psa[i][j] >= t) {
                res += (ll)(uc[i+1]-uc[i]) * (uc[j+1] - uc[j]);
            }
        }
    }
    cout << res;

    return 0;
}