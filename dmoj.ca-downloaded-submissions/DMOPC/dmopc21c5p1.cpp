#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 5e5+5;

string ans[] = {"0", "1", "-1", "-1", "-1", "1 3 5 4 2","1 3 5 4 2 6","7 2 4 6 3 5 1", "1 3 7 5 4 2 6 8","1 3 7 9 5 4 2 6 8","1 3 7 9 5 4 2 6 8 10" };

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    if(n == 0){printf("0\n"); return 0;}
    if(n == 1){printf("1\n"); return 0;}
    else if(n <= 4) {printf("-1\n"); return 0;}

    else if(n <= 10){
        cout << ans[n] << "\n"; return 0;
    }


    for(int i = 1; i <= n; i+= 2){
        if(i == 5) continue;
        printf("%d ", i);
    }
    printf("5 4 ");
    for(int i = 2; i <= n; i+= 2){
        if(i == 4) continue;
        printf("%d", i);
        if(i + 2 <= n) printf(" ");
    }
    printf("\n");

    return 0;
}