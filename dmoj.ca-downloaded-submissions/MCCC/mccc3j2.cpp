#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

string s;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k >> s;

    int res = 0;
    for(char c : s){
        if(c == 'U'){
            if(k == 1) res++, k--;
            else if(k == 0) res++;
            else k--;
        } else if(c == 'D'){
            k++;
        } else{
            if(k == 0) res++;
        }
    }

    cout << res << "\n";

    return 0;
}