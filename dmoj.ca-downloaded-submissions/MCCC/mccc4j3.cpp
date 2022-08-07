#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e6+5;

int a[MM];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n;i ++) cin >> a[i];

    int s = accumulate(a+1, a+n+1, 0),run=0;
    for(int i = 1; i <= n; i++){
        run += a[i];
        if(run*2 == s){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "Andrew is sad.\n";

    return 0;
}