#include <bits/stdc++.h>
using namespace std;

const int MM = 3e3+5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int cmd, n; cin >> cmd >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    int res= 0;
    if(cmd == 1){
        for(int i = 0; i < n; i++){
            res += max(a[i], b[i]);
        }
    } else{
        for(int i = 0; i < n; i++){
            res += max(a[i], b[n-i-1]);
        }
    }
    cout << res;
    return 0;
}