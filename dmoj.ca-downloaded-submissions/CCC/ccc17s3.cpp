#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e3+5, MV=MM*MM;

int a[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        a[x]++;
    }

    int best=0, res = 0;
    for(int h = 1; h <= 4000; h++){
        int even = 0;
        for(int i = 1; i <= 2000; i++){
            if(i >= h) break;

            if(h-i > 2000) continue;

            if(h-i == i){
                even += 2*(a[i]/2);
            } else{
                even += min(a[i], a[h-i]);
            }
        }
        even /= 2;
        if(even > best) {
            best = even;
            res = 1;
        } else if(even == best){
            res++;
        }
    }
    cout << best << " " << res;

    return 0;
}