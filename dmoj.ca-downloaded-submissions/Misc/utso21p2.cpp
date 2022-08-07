#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 5e3+5;

int a[MM*2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k; cin >> k;
    if(k == 0) {cout << "1\n2"; return 0;}
    int n = round(sqrt(k*2));
    // if(n*(n-1)/2 > k) n--;
    
    for(int i = 1; i <= 100; i+=2) a[i] = 2;
    for(int i = 2; i <= 100; i+=2) a[i] = 3;
    for(int i = 1; i <= k- (n*(n-1)/2); i++) a[i] = 1;

    cout << n << '\n';
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';

    return 0;
}