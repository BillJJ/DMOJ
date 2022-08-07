#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e6+5, mod=1e9+7;

int a[MM], f[MM];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    int run=0,res=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];

        run+=a[i];
        run%=k;
        if(run == 0) res = max(res, i);
        if(f[run]) res = max(res, i-f[run]);
        else f[run] = i;
    }
    cout << (res?res:-1);

    return 0;
}