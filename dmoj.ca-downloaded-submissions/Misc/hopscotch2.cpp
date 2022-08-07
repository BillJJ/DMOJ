#include <bits/stdc++.h>
using namespace std;

#define su(x) do{while((x=getchar_unlocked())<48); for(x-=48; 48<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar_unlocked())<45); _sign=x==45; if(_sign) while((x=getchar_unlocked())<48); for(x-=48; 48<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar_unlocked())<33);}while(0)
char _; bool _sign;

typedef long long ll;
typedef pair<long, long> pll;
const int MM = 8388608 + 5;

ll a[MM], dp[MM], previous[MM];
deque<pll> q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, k; su(n); su(k);
    for(int i = 1; i <= n; i++){
        su(a[i]);
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    q.push_back({0, 0});
    for(int i = 1; i <= n+1; i++){
        while(q.front().second < i-k) q.pop_front();
        dp[i] = a[i] + q.front().first;
        previous[i] = q.front().second;

        while(q.back().first >= dp[i]) q.pop_back();

        q.push_back({dp[i], i});
    }

    vector<int> out;
    cout << dp[n+1] << '\n';
    for(int i = previous[n+1]; i > 0; i = previous[i])
        out.push_back(i);

    reverse(begin(out), end(out));
    for(int i : out)
        cout << i << " ";

    return 0;
}