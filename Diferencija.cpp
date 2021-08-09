#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 3e5+5;

ll ans, fx[MM], fi[MM]; stack<int> mx, mi; int n, a[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        while(!mx.empty() && a[i] >= a[mx.top()]) mx.pop();
        while(!mi.empty() && a[i] <= a[mi.top()]) mi.pop();
        int p = mx.empty()? 0:mx.top();
        fx[i] = fx[p] + 1LL*a[i]*(i-p);
        p = mi.empty()? 0:mi.top();
        fi[i] = fi[p] + 1LL*a[i]*(i-p);
        ans += fx[i] - fi[i]; mx.push(i); mi.push(i);
    }
    cout << ans << endl;
}