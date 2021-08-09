#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

int a[505][505], n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n;j++){
            cin >> a[i][j];
        }
    }
    ll total = 0;
    // n^4 lets go probbaly more LMOA
    for(int ri = 1; ri <= n; ri++){
        for(int rj = ri; rj <= n; rj++){
            for(int ci = 1; ci <= n; ci++){
                int least = 200;
                for(int cj = ci; cj <= n; cj++){

                    for(int i = ri; i <= rj; i++){
                        least = min(least, a[i][cj]);
                    }
                    if(least == 100) {
                        total++;
                        printf("(%d, %d) to (%d, %d)\n",  ri, ci, rj, cj);
                    }

                    if(least < 100) break;
                }
            }
        }
    }

    cout << total;

    return 0;
}
