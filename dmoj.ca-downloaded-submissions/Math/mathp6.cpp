#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

double n, m;
double dis(double mid){
    return max((n - mid) * (n - mid) - 3 * (m - mid * mid), (double)0);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    double ans = n/4;
    if(n*n > m*4){
        cout << "no"; return 0;
    }
    double l = ans, r = sqrt(m);
    while(r-l > 0.000001){
        double mid = (l+r)/2;
        if(!dis(mid)) l = mid;
        else r = mid;
    }
    for(double i = r; i >= l; i -= 0.00000001){
        if(dis(i) == 0){
            ans = i;
            break;
        }
    }
    ans = (round((ans*1e8)))*1e-8;
    cout << fixed << setprecision(8);
    cout << ans;

    return 0;
}