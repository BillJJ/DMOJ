#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if(x1==x2){
        cout << "y-axis" << "\n";
    } else if(y1==y2){
        cout << "x-axis\n";
    } else{
        cout << "neither\n";
    }

    return 0;
}