#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 18, MV=1e6;

map<char, char> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 0; i < 10; i++){
        char c; cin >> c;
        m[i+'0'] = c;
    }

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        cout << m[a+'0'];
    }

    return 0;
}