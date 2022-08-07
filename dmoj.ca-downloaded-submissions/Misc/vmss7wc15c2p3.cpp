#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _;
bool _sign;

deque<ll> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll total = 0;
    ll a;
    while (n--) {
        cin >> a;
        if (q.empty())
            q.push_back(a);
        else {
            while (!q.empty() && q.back() < a) {
                total++;
                q.pop_back();
            }
            if (!q.empty() && q.back() == a) {
                if(q.front() == a){
                    total += q.size();
                }
                else{
                    auto iter = q.end();
                    iter--;
                    while (*iter == a) {
                        total++;
                        iter--;
                    }
                    total++;
                }
            } else if (!q.empty() && q.back() > a)
                total++;
            q.push_back(a);
        }
    }

    cout << total;

    return 0;
}