#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int max_num = 200005;

int a[max_num];
int h[max_num];
ll bit[max_num];

void update(int i, ll v){
    for(;i <= max_num; i += i&-i)
        bit[i] = max(bit[i], v);
}

ll get_max(int i){
    ll ret = 0;
    for(; i > 0; i -=i&-i)
        ret = max(bit[i], ret);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    ll ans = 0;
    for(int i = 0; i< n; i++){
        ll res = get_max(a[i] - 1) + h[i];
        ans = max(ans,res);
        update(a[i], res);
    }

    cout << ans;

    return 0;
}