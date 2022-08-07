#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const int MM = 1e4+5;

int a[MM];
int f[3];

vector<int> num[3];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        f[x%3]++;
        num[x%3].push_back(x);
    }

    if(f[1] && f[2] && !f[0]){cout << "impossible\n"; return 0;}
    if(f[0] > f[1]+f[2]+1){cout << "impossible\n"; return 0;}

    int i=1;
    a[0] = 1;
    for(; i <= n && f[0]>1&&f[1]; i++){
        if(a[i-1] == 1){
            a[i] = 0;
            f[0]--;
        } else{
            a[i] = 1;
            f[1]--;
        }
    }
    for(; i <= n && f[1] && f[0]==1; i++){
        a[i] = 1;
        f[1]--;
    }

    for(; i <= n && f[0] && f[2]; i++){
        if(a[i-1] == 0){
            a[i] = 2;
            f[2]--;
        } else{
            a[i] = 0;
            f[0]--;
        }
    }
    for(; i <= n && f[2]; i++){
        a[i] = 2;
        f[2]--;
    }

    for(int j= 1; j <= n;j ++){
        cout << num[a[j]].back() << " \n"[j == n];
        num[a[j]].pop_back();
    }
    

    return 0;
}