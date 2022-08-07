#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

int s[3][MM], g[500];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int tie = 1, a=0,b=0, longest=0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        g[i] = x;
        if(x == 1){
            s[1][i]++;
            a++;
        } else{
            s[2][i]++;
            b++;
        }
        if(a == b) tie++;
        s[1][i] += s[1][i-1];
        s[2][i] += s[2][i-1];
    }

    int run = 0;
    for(int i = 2; i <= n; i++){
        if(g[i-1] == 2 && g[i] == 1){
            if(s[1][i-1] < s[2][i-1]) run = 1;
            else run = 0;
        } else if(g[i-1] == 1 && g[i] == 2){
            if(s[2][i-1] < s[1][i-1]) run = 1;
            else run = 0;
        } else run++;
        if(g[i] == 1){
            if(s[1][i] > s[2][i]) longest = max(longest, run);
        } else if(s[1][i] < s[2][i]) longest = max(longest, run);
    }

    cout << a << " " << b << "\n";
    cout << tie << "\n";
    cout << longest << "\n";

    return 0;
}