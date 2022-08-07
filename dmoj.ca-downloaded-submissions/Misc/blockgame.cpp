//doubles trash!!
// this data is fake!! it should be YYYYYYYYYYYYYYYY

#include <bits/stdc++.h>
using namespace std;
void scan(int &x){ x = 0; char a; for (a = getchar_unlocked(); a <'0' or a>'9'; a = getchar_unlocked()) {} x = a-'0'; for (a = getchar_unlocked(); a >= '0' and a <= '9'; a = getchar_unlocked()) x = x*10 + a-'0';}
template<typename T, typename...A>void scan(T& f, A&...a) { scan(f); scan(a...); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    double n, k, d; scanf("%lf%lf%lf", &n, &k, &d);
    double j; scanf("%lf", &j);

    while(n--){
        int a, b; scan(a, b);
        k += a, d += b;
    }

    if(d == 0){printf("stop hacking!"); return 0;}

    printf((double)k/d >= j ? "Y" : "N");

    return 0;
}