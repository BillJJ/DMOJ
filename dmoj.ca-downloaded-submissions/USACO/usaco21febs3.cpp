#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 505;

ll a[MM], b[MM], n;
stack<ll> stk;

ll total_rectangles(ll x[MM]){
    stk.push(0);
    x[0] = -1;
    ll res = 0;

    for(ll i = 1; i <= n; i++){
        while(x[stk.top()] > x[i]){
            ll index = stk.top(); stk.pop();
            res += 1LL*(i - index)*(index - stk.top())*x[index];
        }
        stk.push(i);
    }

    while(stk.size() > 1){
        ll index = stk.top(); stk.pop();
        res += 1LL*(n+1 - index)*(index - stk.top())*x[index];
    }

    stk.pop();
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    ll total = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1, x; j <= n;j++){
            cin >> x;
            if(x >= 100) a[j]++;
            else a[j] = 0;

            if(x > 100) b[j]++;
            else b[j] = 0;
        }
        total += total_rectangles(a) - total_rectangles(b);
    }
    cout << total;

    return 0;
}