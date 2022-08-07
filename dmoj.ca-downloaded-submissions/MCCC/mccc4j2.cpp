#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e5+5;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, a, b; cin >> n >> a >> b;
    int ta=0, tb=0;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        if(a > x) ta++;
        else ta+=2;

        if(b > y) tb++;
        else tb+=2;
    }

    if(ta == tb) cout << "Tie!";
    else if(ta>tb) cout << "Tommy wins!";
    else cout << "Andrew wins!";
    cout << "\n";

    return 0;
}