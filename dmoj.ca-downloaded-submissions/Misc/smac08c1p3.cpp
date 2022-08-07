#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

int a[MM];
int dp[MM];
deque<int> q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, d; cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[1] = a[1];
    q.push_back(1);

    for(int i = 2; i <= n; i++){
        while(!q.empty() && q.front() < i-d) q.pop_front();

        dp[i] = a[i] + dp[q.front()];

        while(!q.empty() && dp[q.back()] > dp[i]) q.pop_back();
        q.push_back(i);
    }

    cout << dp[n];
    return 0;
}