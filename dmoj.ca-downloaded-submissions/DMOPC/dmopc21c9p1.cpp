#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;
#define int ll 
int a[MM], n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int mi=0,mx = 1;
    cin >> a[1];
    mx = a[1]-1, mi=1;
    int num = a[1];
    for(int i = 2; i < n; i++) {
        cin >> a[i];
        if(i%2 == 0){
            num -= a[i];
            mi = max(mi, num+1);
        } else{
            num += a[i];
            mx = min(mx, num-1);
        }
    }
    cout << max(mx-mi+1, 0LL);
    return 0;
}