#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 10000001;
int a[MM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int s, f; cin >> s >> f;
        a[s]++; a[f]--;
    }
    int total = 0;

    for(int i = 1; i < MM; i++){
        a[i] += a[i-1];
        total = max(total, a[i]);
    }

    cout << total;

    return 0;
}