#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int a[3];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[2]-a[0] == 2){
        cout << "0\n0"; return 0;
    }
    if(a[2]-a[1] == 2 || a[1] - a[0] == 2) cout << "1\n";
    else cout << "2\n";
    cout << a[2]-a[0]-2 - min(a[2]-a[1]-1, a[1]-a[0]-1);

    return 0;
}