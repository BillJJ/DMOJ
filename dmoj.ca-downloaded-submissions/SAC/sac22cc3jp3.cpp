#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    double d=1;
    while(n--){
        char c; cin >> c;
        switch(c){
            case'A': break;
            case'B':d*=0.8; break;
            case'C':d*=0.6;break;
            case'D':d*=0.4;break;
            case'E':d*=0.2;break;
        }
    }
    cout << d << "\n";

    return 0;
}