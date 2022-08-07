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

    int n; cin >> n;
    vector<double> a (n);

    for(double &x : a) cin >> x;

    int cmd; cin >> cmd;
    while(cmd != 77){
        if(cmd == 99){
            int i, l; cin >> i >> l;
            i--;
            double left = a[i] * l / 100;
            double right = a[i] - left;
            a[i] = left;
            a.insert(a.begin() + i+1, right);
        }
        else if(cmd == 88){
            int i; cin >> i;
            i--;
            a[i] += a[i+1];
            a.erase(a.begin() + i+1);
        }
        cin >> cmd;
    }

    for(double &i : a)
        cout << round(i) << ' ';

    return 0;
}