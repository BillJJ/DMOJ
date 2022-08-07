#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef pair<int, int> pii;

vector<pii> q; // val : pos

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(q.empty()){q.push_back({a, i}); cout << i << " "; continue;}

        while(!q.empty() && q.back().first <= a){
            q.pop_back();
        }
        if(q.empty()){q.push_back({a, i}); cout << i << " "; continue;}

        cout << i - q.back().second << " ";
        q.push_back({a, i});
    }

    return 0;
}