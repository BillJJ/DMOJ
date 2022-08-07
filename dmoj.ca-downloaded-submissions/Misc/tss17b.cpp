#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1414214;
int a[MM + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q; su(n); su(q);

    while(n--){
        ll x, y; si(x); si(y);
        x = abs(x), y = abs(y);
        a[(int)ceil(sqrt(x*x + y*y))]++;
    }
    for(int i = 1; i <= MM; i++){
        a[i] += a[i-1];
    }
    while(q--){
        int i; su(i);
        cout << a[i] << '\n';
    }

    return 0;
}