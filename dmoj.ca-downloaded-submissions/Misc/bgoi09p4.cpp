#include <stdio.h>
#include <deque>
#include <vector>
using namespace std;
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _;
bool _sign;

deque<int> q;
int h[1000005];
int jump[1000005];
vector<int> out;

int main() {
    int n; su(n);
    for(int i = 0; i < n; i++) su(h[i]);
    for(int i = 0; i < n; i++) su(jump[i]);

    for(int i = n-1; i >= 0; i--){
        int a = h[i];
        while(!q.empty() && q.back() <= a){
            q.pop_back();
        }
        if(q.empty()){
            out.push_back(-1);
        }
        else{
            if(jump[i] <= q.size()) out.push_back(q[q.size() - jump[i]]);
            else out.push_back(-1);
        }
        q.push_back(a);
    }
    for(int i = n-1; i >= 0; i--) printf("%d ", out[i]);
    return 0;
}