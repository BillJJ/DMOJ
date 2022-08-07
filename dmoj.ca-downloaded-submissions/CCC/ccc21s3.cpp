#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct frien{
    int p, w, d;
    frien(int p, int w, int d) : p(p), w(w), d(d){};
};

vector<frien> f;

ll calc(int pos){
    ll oof = 0;
    for(frien bot : f){
        ll dis = (abs(pos - bot.p)-bot.d);
        if(dis <= 0) continue;
        oof += dis*bot.w;
    }
    return oof;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n, p, w, d; cin >> n;
    int l = 200000, r = 0;

    for(int i = 0; i < n; i++){
        cin >> p >> w >> d;
        l = min(l, p);
        r = max(r, p);
        f.push_back(frien(p, w, d));
    }
    ll total = LONG_LONG_MAX;
    while(l <= r){
        ll mid = ((ll)l+r)/2;
        ll right = calc(mid);
        if(mid == 0){
            total = min(right, total);
            break;
        }
        ll left = calc(mid-1);

        if(left < right){
            r = mid-1;
            total = min(left, total);
        }
        else{
            l = mid + 1;
            total = min(right, total);
        }
    }

    cout << total;
    return 0;
}