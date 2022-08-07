#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 5e6+5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int res = 0;
    while(n > 1){

        for(int b = 2; b <= n; b++){
            if(n % b == 0){
                res += (b-1);
                n -= n/b;
                break;
            }
        }

    }
    cout << res;
    return 0;
}