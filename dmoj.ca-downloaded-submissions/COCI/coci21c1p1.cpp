#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

int p[MM], stk[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int one=0,two=0;
    fill(p,p+10, -200);
    for (int i = 1; i <= n; ++i) {
        int t, a, b; cin >> t >> a >> b;

        int point = 100;
        if(t-p[a] <= 10) {
            stk[a]++;
            point += 50;
        } else{
            stk[a] = 0;
        }
        p[a] = t;
        if(a <= 4){
            one += point;
        } else{
            two += point;
        }
    }
    cout << one << " " << two << "\n";

    return 0;
}