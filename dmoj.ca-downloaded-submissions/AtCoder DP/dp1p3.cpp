#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int max_num = 1000005;

int a[max_num];
int a2[max_num];
int bit[max_num];

unordered_map<int, int> pls_work;

void update(int i, int v){
    for(;i <= max_num; i += i&-i)
        bit[i] = max(bit[i], v);
}

int get_max(int i){
    int ret = 0;
    for(; i > 0; i -=i&-i)
        ret = max(bit[i], ret);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a2[i] = a[i];
    }

    sort(begin(a2), begin(a2) + n);
    for(int i = 0; i < n; i++){
        pls_work[a2[i]] = i;
    }

    for(int i = 0; i < n; i++) a[i] = pls_work[a[i]];

    int ans = 0;
    for(int i = 0; i< n; i++){
        int res = get_max(a[i]);
        ans = max(ans, res+1);
        update(a[i]+1, res+1);
    }

    cout << ans;

    return 0;
}