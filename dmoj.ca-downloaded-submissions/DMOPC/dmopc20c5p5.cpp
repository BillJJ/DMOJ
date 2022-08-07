#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    srand(time(0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << (__builtin_popcount(i+j)&1 ? "Y" : "B");
        cout << "\n";
    }

    return 0;
}