#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _;
bool _sign;

const int MM = 7.5e5 + 5;
int r[MM], rw[MM], rwr[MM];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n; string s; cin >> s;

        r[0] = s[0] == 'W';
        rw[0] = INT_MAX-10, rwr[0] = INT_MAX-10;
        for(int i = 1; i < n; i++){
            r[i] = r[i-1] + (s[i] == 'W');
            rw[i] = min(rw[i-1], r[i-1]) + (s[i] == 'R');
            rwr[i] = min(rwr[i-1], rw[i-1]) + (s[i] == 'W');
        }
        cout << rwr[n-1] << "\n";
    }
    return 0;
}