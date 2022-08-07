#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second

const int MM = 2e6+5, MV=5e6+5;

int a[MM];
bool vis[MV];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[a[i]]){
            res++;
            for(int j = a[i]; j < MV; j+= a[i]){
                vis[j] = 1;
            }
        }
    }

    cout << res << "\n";

    return 0;
}