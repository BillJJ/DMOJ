#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; scanf("%d", &n);

    long long m = 0;
    while(n--){
        int c, v; scanf("%d%d", &c, &v);
        if(v < 1 || c < 1) continue;
        m += c;
    }
    printf("%lld", m);
    return 0;
}