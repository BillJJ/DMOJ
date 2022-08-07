#include <bits/stdc++.h>
#define sb(x) do{while((_=getchar())<48); x=(_-48);}while(0)
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
char _; bool _sign;
using namespace std;

vector<int> a;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n; su(n);
    while(n--){
        int num; su(num);
        auto iter = lower_bound(a.begin(), a.end(), num);
        if(iter == a.end()){
            a.push_back(num);
        }
        else{
            *iter = num;
        }
    }
    cout << a.size();

    return 0;
}