#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e5+5;

ll psa[MM*2];
deque<ll> q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> psa[i];
        psa[i+n] = psa[i];
    }

    for(int i = 1; i < n*2; i++){
        psa[i] += psa[i-1];
    }

    ll res = 0;

    for(int i = 0; i < k-1; i++){
        while(!q.empty() && psa[q.back()] > psa[i]) q.pop_back();
        q.push_back(i);
    }

    for(int i = k-1; i < n+k; i++){
        while(!q.empty() && q.front() < i-k) q.pop_front();

        res = max(res, psa[i] - psa[q.front()]);

        while(!q.empty() && psa[q.back()] > psa[i]) q.pop_back();
        q.push_back(i);
    }

    cout << res;

    return 0;
}