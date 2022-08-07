#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int r[750005];
int w[750005];
int n; string s;

void solve(){
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') r[i]++;
        else w[i]++;
    }
    for(int i = 1; i < n; i++){
        r[i] += r[i-1];
        w[i] += w[i-1];
    }
    int total = INT_MAX;
    // r, i w, j r
    for(int i = 0; i < n-2; i++){
        int res = INT_MAX;
        for(int j = i+1; j < n-1; j++){
            res = min(res, r[j] - r[i] + w[n-1] - w[j]);
        }
        res += w[i];
        total = min(total, res);
    }
    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        memset(r, 0, sizeof r);
        memset(w, 0, sizeof w);

        cin >> n;
        cin >> s;
        solve();
    }

    return 0;
}