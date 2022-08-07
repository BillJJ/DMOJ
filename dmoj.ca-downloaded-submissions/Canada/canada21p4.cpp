#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, k; cin >> n >> k;
    ll t, x, y; cin >> t >> x >> y;
    ll l = x, r = x, bot = y, top = y;
    ll res = 0;
    while(--n){
        ll prevt = t;
        cin >> t >> x >> y;
        ll move = k*(t-prevt);
        l += move, r -= move, bot += move, top -= move;
        l = min(l, x), r = max(r, x), bot = min(bot, y), top = max(top, y);
        res = max({res, r-l, top-bot});
    }

    cout << res;
    return 0;
}